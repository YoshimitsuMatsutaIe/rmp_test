

#include "../../include/rmp_node.hpp"
#include "../../robot_model_sice/include/sice.hpp"
#include "../../include/rmp_leaf.hpp"
#include "../../include/mappings.hpp"
#include "../../include/rmp_node.hpp"
#include "../../include/simulator.hpp"
#include "../../include/rmp_tree.hpp"

#include <omp.h>
#include <eigen3/Eigen/Core>
#include <iostream>
#include <vector>
#include <string>


int main()
{
    using std::cout;
    using std::endl;
    using Eigen::VectorXd;
    using std::vector;

    cout << "running...\n" << endl;

    namespace rm = sice;

    VectorXd og(2);  //目標点位置
    VectorXd og_dot(2);  //目標点速度
    og << 2.0, 1.0;
    og_dot << 0.0, 0.0;

    const double TiME_INTERVAL = 6.0;
    const double dt = 1e-2;

    cout << "construct root start" << endl;
    /* root */
    mapping_base::Identity root_mappings;
    rmp_flow::Root root(4, 0, "root", &root_mappings);
    VectorXd q0(4), q0_dot(4);
    rm::Kinematics::set_q_neutral(q0);
    q0_dot = VectorXd::Zero(4);

    root.set_state(q0, q0_dot);
    root.set_debug(true);


    /* node 作成*/
    cout << "constract node start..." << endl;

    // ジョイント制限
    VectorXd q_neutral(4), q_max(4), q_min(4);
    rm::Kinematics::set_q_neutral(q_neutral);
    rm::Kinematics::set_q_max(q_max);
    rm::Kinematics::set_q_min(q_min);
    mapping_base::Identity id_mappings2;  //恒等写像
    rmp2::Joint_Limit_Avoidance jl(
        root.self_dim, root.self_dim, "jl-avoidance", &id_mappings2,
        0.01, 0.05, 1.0, 0.1, q_max, q_min, q_neutral
    );
    root.add_child(&jl);
    cout << "jl add to ee done" << endl;


    // 構造
    vector<std::size_t> model_struct = rm::Control_Point::calc_points_mapping();
    auto frame_num = model_struct.size();
    
    /* 制御点のマップを構成 */
    vector<vector<mapping_base::Identity>> mappings;
    for (int i=0; i<frame_num; ++i){
        //cout << "i = " << i << endl;
        vector<mapping_base::Identity> temp_mappings_;
        for (int j=0; j<model_struct[i]; ++j){
            //cout << "  j = " << j << endl;
            temp_mappings_.push_back(rm::Control_Point(i, j));
            cout << "now map name is " << temp_mappings_[j].name << endl;
            //cout << "and jo = \n" << temp_mappings_[j].print_state() << endl;
        }
        mappings.push_back(temp_mappings_);
    }
    auto [ee_frame_num, ee_n] = rm::Kinematics::get_ee_id();

    /* マップのチェック */
    for (auto hoge: mappings){
        for (auto h: hoge){
            cout << h.name << endl;
        }
    }

    /* 制御点のnode構築 */
    vector<vector<rmp_flow::Node>> cpoint_nodes;  //ノード
    for (int i=0; i<frame_num; ++i){
        vector<rmp_flow::Node> temp_nodes_;
        for (int j=0; j<model_struct[i]; ++j){
            std::string name;
            if (i == frame_num-1){
                name = "ee";
                temp_nodes_.push_back(rmp_flow::Node(3, root.self_dim, name, &mappings[i][j]));
            }
            else{
                name = "cpoints_" + std::to_string(i) + "_" + std::to_string(j);
                temp_nodes_.push_back(rmp_flow::Leaf_Base(2, root.self_dim, name, &mappings[i][j]));
            }
        }
        cpoint_nodes.push_back(temp_nodes_);
    }


    cout << "adding child to root..." << endl;
    for (int i=0; i<frame_num; ++i){
        for (int j=0; j<model_struct[i]; ++j){
            root.add_child(&cpoint_nodes[i][j]);
        }
    }
    cout << "done" << endl;
    
    cout << "make attractor-node & add to ee-node" << endl;
    mapping_base::Identity id_mappings;
    rmp2::Goal_Attractor attractor(
        2, 2, "ee-attractor", &id_mappings,
        5.0, 5.0, 0.15, 1.0, 1.0, 10.0, 0.1, 0.15, 0.5,
        og, og_dot
    );
    cpoint_nodes[frame_num-1][0].add_child(&attractor);
    cout << "done 10%\n" << endl;

    root.print_state_all_node();
    cout << "print all done!!!" << endl;
    root.pushforward();
    cout << "push done" << endl;
    root.print_state_all_node();

    // root.pullback();
    // root.print_state_all_node();


    //rmp_flow::RMP_Tree tree(&root, "test_tree");
    //tree.set_debug(false);
    //tree.run(TiME_INTERVAL, dt);





    cout << "done!!" << endl;
}