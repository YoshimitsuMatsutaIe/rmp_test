#ifndef RMP2_ATRACTTOR_XI_3D__H
#define RMP2_ATRACTTOR_XI_3D__H
#include <cmath>
#include <eigen3/Eigen/Core>
namespace rmp2_attractor_xi_3d
{
    using std::exp;
    using std::pow;
    using std::sqrt;
    void func(double alpha, double epsilon, double sigma_alpha, double sigma_gamma, double w_l, double w_u, const Eigen::VectorXd &x, const Eigen::VectorXd &x_dot, Eigen::VectorXd &out);
}
#endif