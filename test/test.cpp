#include "../include/node.hpp"
#include "../include/model_simple_arm.hpp"
#include "/usr/include/eigen3/Eigen/Core"
#include <iostream>


// 恒等写像
void calc_x_(const Eigen::VectorXd& y, Eigen::VectorXd& x)
{
    x = y;
}

void calc_J_(const Eigen::VectorXd &y, Eigen::MatrixXd &J)
{
    J = Eigen::MatrixXd::Zero(2, 2);
}


void calc_J_dot_(const Eigen::VectorXd &y, Eigen::MatrixXd &J_dot)
{
    J_dot = Eigen::MatrixXd::Zero(2, 2);
}

void calc_rmp_func(
    const Eigen::VectorXd &x,
    const Eigen::VectorXd &x_dot,
    Eigen::VectorXd &f, Eigen::MatrixXd &M
)
{
    f = x;
    M = Eigen::MatrixXd::Zero(2, 2);
}



int main()
{
    std::cout << "running...\n" << std::endl;


    model_simple_arm::Kinematics_Model kim(1.0, 1.0, 1.0, 1.0);

    double dt = 0.01;
    rmp_node::Node root(4, "root", dt);
    Eigen::VectorXd q0(4), q0_dot(4);
    q0 << 0.0, 0.0, 0.0;
    q0_dot << 0.0, 0.0, 0.0, 0.0;
    root.set_initial_state(q0, q0_dot);

    rmp_node::Node node0(2, "x0", dt);
    root.add_child(&node0);
    node0.set_mappings(kim.x0, kim.J0, &calc_J_dot_, &calc_rmp_func);

    rmp_node::Node node1(2, "x1", dt);
    root.add_child(&node1);
    node1.set_mappings(&calc_x_, &calc_J_, &calc_J_dot_, &calc_rmp_func);

    rmp_node::Node node2(2, "x2", dt);
    root.add_child(&node2);

    rmp_node::Node node3(2, "x3", dt);
    root.add_child(&node3);


    root.set_mappings(&calc_x_, &calc_J_, &calc_J_dot_, &calc_rmp_func);
    
    

    root.pushforward();

    root.pullback();




    std::cout << "\ndone!" << std::endl;
}