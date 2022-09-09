#include "../include/rmp_multi.hpp"


void rmp_multi::solve(
    const VectorXd& state,
    const vector<mapping_base::Identity*> mappings,
    rmp2::goal_attractor_natural_form& attractor,
    rmp2::obs_avoidance_natural_form& obs_avoidance,
    rmp2::jl_avoidance_natural_form& jl_avoidance,
    const VectorXd& g, const VectorXd& g_dot,
    const std::vector<VectorXd>& o_s, const std::vector<VectorXd>& o_dot_s,
    const int ee_num, const int cpoint_num, const int c_dim, const int t_dim,
    VectorXd& state_dot
)
{
    VectorXd q = state.head(c_dim);
    VectorXd q_dot = state.tail(c_dim);
    
    VectorXd root_f = VectorXd::Zero(c_dim);
    MatrixXd root_M = MatrixXd::Zero(c_dim, c_dim);


    jl_avoidance(q, q_dot, root_f, root_M);

    #pragma omp declare reduction(+ : Eigen::MatrixXd : omp_out=omp_out+omp_in) initializer(omp_priv = omp_orig)
    #pragma omp declare reduction(+ : Eigen::VectorXd : omp_out=omp_out+omp_in) initializer(omp_priv = omp_orig)
    #pragma omp parallel
    {
        #pragma omp parallel for reduction(+: root_f) reduction(+: root_M)
        for (int i=0; i<cpoint_num; ++i){
            VectorXd x(t_dim), x_dot(t_dim), f(t_dim), temp_f(t_dim);
            MatrixXd J(t_dim, c_dim), J_dot(t_dim, c_dim), M(t_dim, t_dim), temp_M(t_dim, t_dim);;
            mappings[i]->phi(q, x);
            mappings[i]->jacobian(q, J);
            mappings[i]->jacobian_dot(q, q_dot, J_dot);
            mappings[i]->velovity(q_dot, J, x_dot);
            
            #pragma omp parallel for reduction(+: f) reduction(+: M)
            for (int j=0; j<o_s.size(); ++j){
                f = VectorXd::Zero(t_dim);
                M = MatrixXd::Zero(t_dim, t_dim);
                obs_avoidance(x, x_dot, o_s[j], o_dot_s[j], temp_f, temp_M);
                f += temp_f;
                M += temp_M;
                if (j == ee_num){
                    attractor(x, x_dot, g, g_dot, temp_f, temp_M);
                    f += temp_f;
                    M += temp_M;
                }
            }
            root_f += J.transpose() * (f - (M * J_dot * x_dot));
            root_M += J.transpose() * M * J;
        }
    }

    state_dot.head(c_dim) = q_dot;
    //state_dot.tail(c_dim) = rmp_flow::pseudoInverse(root_M) * root_f;
    state_dot.tail(c_dim) = root_M.completeOrthogonalDecomposition().pseudoInverse() * root_f;
}




std::tuple<rmp2::goal_attractor_natural_form, rmp2::obs_avoidance_natural_form, rmp2::jl_avoidance_natural_form>
rmp_multi::make_rmp_natural_form(
    const std::unordered_map<std::string, std::unordered_map<std::string, double>>& rmp_param,
    int t_dim, std::string robot_model
)
{

    auto ap = rmp_param.at("goal_attractor");
    rmp2::goal_attractor_natural_form at(
        t_dim,
        ap["max_speed"],
        ap["gain"],
        ap["sigma_alpha"],
        ap["sigma_gamma"],
        ap["wu"],
        ap["wl"],
        ap["alpha"],
        ap["epsilon"]
    );

    auto op = rmp_param.at("obstacle_avoidnce");
    rmp2::obs_avoidance_natural_form obs(
        op["scale_rep"],
        op["scale_damp"],
        op["gain"],
        op["sigma"],
        op["rw"]
    );

    VectorXd q_neutoral, q_max, q_min;
    if (robot_model == "sice"){
        namespace rm = sice;
        rm::Kinematics::set_q_neutral(q_neutoral);
        rm::Kinematics::set_q_max(q_max);
        rm::Kinematics::set_q_min(q_min);
    }
    else if (robot_model == "franka_eika"){
        namespace rm = franka_emika;
        rm::Kinematics::set_q_neutral(q_neutoral);
        rm::Kinematics::set_q_max(q_max);
        rm::Kinematics::set_q_min(q_min);
    }

    auto jp = rmp_param.at("joint_limit_avoidance");
    rmp2::jl_avoidance_natural_form jl(
        jp["gamma_p"],
        jp["gamma_d"],
        jp["lam"],
        jp["sigma"],
        q_max, q_min, q_neutoral
    );

    return {at, obs, jl};
}