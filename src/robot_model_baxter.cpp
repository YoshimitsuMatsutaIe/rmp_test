#include <iostream>
#include <cmath>
#include "/usr/include/eigen3/Eigen/Core"

#include "../include/robot_model_baxter.hpp"
#include "../baxter/include/baxter.hpp"

robot_model_baxter::Joint_limitation::Joint_limitation(void)
{
    
    q_max = VectorXd::Zero(7);
    q_min = VectorXd::Zero(7);
    q_neutral = VectorXd::Zero(7);

    q_neutral << 0.0, -31.0, 0.0, 43.0, 0.0, 72.0, 0.0;
    q_max << 51.0, 60.0, 173.0, 150.0, 175.0, 120.0, 175.0;
    q_min << -141.0, -123.0, -173.0, -3.0, -175.0, -90.0, -175.0;

    q_neutral *= M_PI / 180.;
    q_max *= M_PI / 180.;
    q_min *= M_PI / 180.;

}


robot_model_baxter::Base::Base(void)
{
    this->L = 278e-3;
    this->h = 64e-3;
    this->H = 1104e-3;
    this->L0 = 270.35e-3;
    this->L1 = 69e-3;
    this->L2 = 364.35e-3;
    this->L3 = 69e-3;
    this->L4 = 374.29e-3;
    this->L5 = 10e-3;
    this->L6 = 368.3e-3;
}


void robot_model_baxter::X0::phi(const VectorXd &q, VectorXd &out)
{
    out(0) = -L;
    out(1) = -h;
    out(2) = H + L0;
}

void robot_model_baxter::X1::phi(const VectorXd &q, VectorXd &out)
{
    out(0) = -L + L1*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]));
    out(1) = L1*(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0])) - h;
    out(2) = H + L0;
}

void robot_model_baxter::X2::phi(const VectorXd &q, VectorXd &out)
{
    out(0) = -L + L1*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0])) + L2*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1]);
    out(1) = L1*(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0])) + L2*(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1]) - h;
    out(2) = H + L0 - L2*std::sin(q[1]);
}

void robot_model_baxter::X3::phi(const VectorXd &q, VectorXd &out)
{
    out(0) = -L + L1*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0])) + L2*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1]) + L3*(-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]));
    out(1) = L1*(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0])) + L2*(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1]) + L3*(-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2])) - h;
    out(2) = H + L0 - L2*std::sin(q[1]) - L3*std::cos(q[1])*std::cos(q[2]);
}

void robot_model_baxter::X4::phi(const VectorXd &q, VectorXd &out)
{
    out(0) = -L + L1*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0])) + L2*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1]) + L3*(-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2])) - L4*(-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) - (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3]));
    out(1) = L1*(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0])) + L2*(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1]) + L3*(-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2])) - L4*(-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) - (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3])) - h;
    out(2) = H + L0 - L2*std::sin(q[1]) - L3*std::cos(q[1])*std::cos(q[2]) - L4*(std::sin(q[1])*std::cos(q[3]) + std::sin(q[3])*std::cos(q[1])*std::cos(q[2]));
}

void robot_model_baxter::X5::phi(const VectorXd &q, VectorXd &out)
{
    out(0) = -L + L1*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0])) + L2*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1]) + L3*(-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2])) - L4*(-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) - (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3])) + L5*((((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::sin(q[4]) + (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::cos(q[4]));
    out(1) = L1*(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0])) + L2*(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1]) + L3*(-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2])) - L4*(-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) - (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3])) + L5*(((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::sin(q[4]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::cos(q[4])) - h;
    out(2) = H + L0 - L2*std::sin(q[1]) - L3*std::cos(q[1])*std::cos(q[2]) - L4*(std::sin(q[1])*std::cos(q[3]) + std::sin(q[3])*std::cos(q[1])*std::cos(q[2])) + L5*((std::sin(q[1])*std::sin(q[3]) - std::cos(q[1])*std::cos(q[2])*std::cos(q[3]))*std::cos(q[4]) + std::sin(q[2])*std::sin(q[4])*std::cos(q[1]));
}

void robot_model_baxter::X6::phi(const VectorXd &q, VectorXd &out)
{
    out(0) = -L + L1*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0])) + L2*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1]) + L3*(-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2])) - L4*(-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) - (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3])) + L5*((((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::sin(q[4]) + (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::cos(q[4]));
    out(1) = L1*(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0])) + L2*(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1]) + L3*(-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2])) - L4*(-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) - (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3])) + L5*(((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::sin(q[4]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::cos(q[4])) - h;
    out(2) = H + L0 - L2*std::sin(q[1]) - L3*std::cos(q[1])*std::cos(q[2]) - L4*(std::sin(q[1])*std::cos(q[3]) + std::sin(q[3])*std::cos(q[1])*std::cos(q[2])) + L5*((std::sin(q[1])*std::sin(q[3]) - std::cos(q[1])*std::cos(q[2])*std::cos(q[3]))*std::cos(q[4]) + std::sin(q[2])*std::sin(q[4])*std::cos(q[1]));
}

void robot_model_baxter::EE::phi(const VectorXd &q, VectorXd &out)
{
    out(0) = -L + L1*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0])) + L2*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1]) + L3*(-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2])) - L4*(-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) - (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3])) + L5*((((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::sin(q[4]) + (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::cos(q[4])) + L6*(((((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::sin(q[4]) + (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::cos(q[4]))*std::sin(q[5]) + (((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) + (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3]))*std::cos(q[5]));
    out(1) = L1*(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0])) + L2*(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1]) + L3*(-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2])) - L4*(-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) - (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3])) + L5*(((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::sin(q[4]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::cos(q[4])) + L6*((((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::sin(q[4]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::cos(q[4]))*std::sin(q[5]) + ((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3]))*std::cos(q[5])) - h;
    out(2) = H + L0 - L2*std::sin(q[1]) - L3*std::cos(q[1])*std::cos(q[2]) - L4*(std::sin(q[1])*std::cos(q[3]) + std::sin(q[3])*std::cos(q[1])*std::cos(q[2])) + L5*((std::sin(q[1])*std::sin(q[3]) - std::cos(q[1])*std::cos(q[2])*std::cos(q[3]))*std::cos(q[4]) + std::sin(q[2])*std::sin(q[4])*std::cos(q[1])) + L6*(((std::sin(q[1])*std::sin(q[3]) - std::cos(q[1])*std::cos(q[2])*std::cos(q[3]))*std::cos(q[4]) + std::sin(q[2])*std::sin(q[4])*std::cos(q[1]))*std::sin(q[5]) + (-std::sin(q[1])*std::cos(q[3]) - std::sin(q[3])*std::cos(q[1])*std::cos(q[2]))*std::cos(q[5]));
}



void robot_model_baxter::X0::jacobian(const VectorXd &q, MatrixXd &out)
{
out[0] = 0;
out[1] = 0;
out[2] = 0;
out[3] = 0;
out[4] = 0;
out[5] = 0;
out[6] = 0;
out[7] = 0;
out[8] = 0;
out[9] = 0;
out[10] = 0;
out[11] = 0;
out[12] = 0;
out[13] = 0;
out[14] = 0;
out[15] = 0;
out[16] = 0;
out[17] = 0;
out[18] = 0;
out[19] = 0;
out[20] = 0;
}

void robot_model_baxter::X1::jacobian(const VectorXd &q, MatrixXd &out)
{
out[0] = L1*((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]));
out[1] = 0;
out[2] = 0;
out[3] = 0;
out[4] = 0;
out[5] = 0;
out[6] = 0;
out[7] = L1*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]));
out[8] = 0;
out[9] = 0;
out[10] = 0;
out[11] = 0;
out[12] = 0;
out[13] = 0;
out[14] = 0;
out[15] = 0;
out[16] = 0;
out[17] = 0;
out[18] = 0;
out[19] = 0;
out[20] = 0;
}

void robot_model_baxter::X2::jacobian(const VectorXd &q, MatrixXd &out)
{out[0] = L1*((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0])) + L2*((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1]);
out[1] = -L2*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1]);
out[2] = 0;
out[3] = 0;
out[4] = 0;
out[5] = 0;
out[6] = 0;
out[7] = L1*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0])) + L2*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1]);
out[8] = -L2*(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1]);
out[9] = 0;
out[10] = 0;
out[11] = 0;
out[12] = 0;
out[13] = 0;
out[14] = 0;
out[15] = -L2*std::cos(q[1]);
out[16] = 0;
out[17] = 0;
out[18] = 0;
out[19] = 0;
out[20] = 0;

}

void robot_model_baxter::X3::jacobian(const VectorXd &q, MatrixXd &out)
{
out[0] = L1*((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0])) + L2*((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1]) + L3*((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + (-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]));
out[1] = -L2*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1]) + L3*(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[2]);
out[2] = L3*(-(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]));
out[3] = 0;
out[4] = 0;
out[5] = 0;
out[6] = 0;
out[7] = L1*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0])) + L2*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1]) + L3*((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]));
out[8] = -L2*(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1]) + L3*((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[2]);
out[9] = L3*(((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]));
out[10] = 0;
out[11] = 0;
out[12] = 0;
out[13] = 0;
out[14] = 0;
out[15] = -L2*std::cos(q[1]) + L3*std::sin(q[1])*std::cos(q[2]);
out[16] = L3*std::sin(q[2])*std::cos(q[1]);
out[17] = 0;
out[18] = 0;
out[19] = 0;
out[20] = 0;
}

void robot_model_baxter::X4::jacobian(const VectorXd &q, MatrixXd &out)
{
out[0] = L1*((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0])) + L2*((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1]) + L3*((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + (-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2])) - L4*((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) - (-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3]));
out[1] = -L2*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1]) + L3*(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[2]) - L4*(-(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[3]) - (-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1])*std::cos(q[2]));
out[2] = L3*(-(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2])) - L4*((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::sin(q[3]);
out[3] = -L4*(-(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + (((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]));
out[4] = 0;
out[5] = 0;
out[6] = 0;
out[7] = L1*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0])) + L2*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1]) + L3*((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2])) - L4*((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3]));
out[8] = -L2*(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1]) + L3*((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[2]) - L4*(-((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[3]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1])*std::cos(q[2]));
out[9] = L3*(((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2])) - L4*(-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]))*std::sin(q[3]);
out[10] = -L4*(-((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + ((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]));
out[11] = 0;
out[12] = 0;
out[13] = 0;
out[14] = 0;
out[15] = -L2*std::cos(q[1]) + L3*std::sin(q[1])*std::cos(q[2]) - L4*(-std::sin(q[1])*std::sin(q[3])*std::cos(q[2]) + std::cos(q[1])*std::cos(q[3]));
out[16] = L3*std::sin(q[2])*std::cos(q[1]) + L4*std::sin(q[2])*std::sin(q[3])*std::cos(q[1]);
out[17] = -L4*(-std::sin(q[1])*std::sin(q[3]) + std::cos(q[1])*std::cos(q[2])*std::cos(q[3]));
out[18] = 0;
out[19] = 0;
out[20] = 0;
}

void robot_model_baxter::X5::jacobian(const VectorXd &q, MatrixXd &out)
{
out[0] = L1*((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0])) + L2*((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1]) + L3*((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + (-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2])) - L4*((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) - (-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3])) + L5*(((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]))*std::sin(q[4]) + ((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + ((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + (-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::cos(q[4]));
out[1] = -L2*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1]) + L3*(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[2]) - L4*(-(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[3]) - (-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1])*std::cos(q[2])) + L5*(((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2])*std::sin(q[4])*std::cos(q[1]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[3]) + (-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[2])*std::cos(q[3]))*std::cos(q[4]));
out[2] = L3*(-(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2])) - L4*((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::sin(q[3]) + L5*((-(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::cos(q[3])*std::cos(q[4]) + (((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[4]));
out[3] = -L4*(-(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + (((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3])) + L5*((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) - (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3]))*std::cos(q[4]);
out[4] = L5*((((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::cos(q[4]) - (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::sin(q[4]));
out[5] = 0;
out[6] = 0;
out[7] = L1*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0])) + L2*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1]) + L3*((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2])) - L4*((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3])) + L5*(((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + ((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::cos(q[4]) + (((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::sin(q[4]));
out[8] = -L2*(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1]) + L3*((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[2]) - L4*(-((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[3]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1])*std::cos(q[2])) + L5*((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2])*std::sin(q[4])*std::cos(q[1]) + (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[3]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[2])*std::cos(q[3]))*std::cos(q[4]));
out[9] = L3*(((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2])) - L4*(-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]))*std::sin(q[3]) + L5*((((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]))*std::cos(q[3])*std::cos(q[4]) + ((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[4]));
out[10] = -L4*(-((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + ((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3])) + L5*(((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) - (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3]))*std::cos(q[4]);
out[11] = L5*(((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::cos(q[4]) - (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::sin(q[4]));
out[12] = 0;
out[13] = 0;
out[14] = 0;
out[15] = -L2*std::cos(q[1]) + L3*std::sin(q[1])*std::cos(q[2]) - L4*(-std::sin(q[1])*std::sin(q[3])*std::cos(q[2]) + std::cos(q[1])*std::cos(q[3])) + L5*((std::sin(q[1])*std::cos(q[2])*std::cos(q[3]) + std::sin(q[3])*std::cos(q[1]))*std::cos(q[4]) - std::sin(q[1])*std::sin(q[2])*std::sin(q[4]));
out[16] = L3*std::sin(q[2])*std::cos(q[1]) + L4*std::sin(q[2])*std::sin(q[3])*std::cos(q[1]) + L5*(std::sin(q[2])*std::cos(q[1])*std::cos(q[3])*std::cos(q[4]) + std::sin(q[4])*std::cos(q[1])*std::cos(q[2]));
out[17] = -L4*(-std::sin(q[1])*std::sin(q[3]) + std::cos(q[1])*std::cos(q[2])*std::cos(q[3])) + L5*(std::sin(q[1])*std::cos(q[3]) + std::sin(q[3])*std::cos(q[1])*std::cos(q[2]))*std::cos(q[4]);
out[18] = L5*(-(std::sin(q[1])*std::sin(q[3]) - std::cos(q[1])*std::cos(q[2])*std::cos(q[3]))*std::sin(q[4]) + std::sin(q[2])*std::cos(q[1])*std::cos(q[4]));
out[19] = 0;
out[20] = 0;
}

void robot_model_baxter::X6::jacobian(const VectorXd &q, MatrixXd &out)
{
out[0] = L1*((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0])) + L2*((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1]) + L3*((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + (-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2])) - L4*((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) - (-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3])) + L5*(((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]))*std::sin(q[4]) + ((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + ((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + (-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::cos(q[4]));
out[1] = -L2*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1]) + L3*(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[2]) - L4*(-(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[3]) - (-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1])*std::cos(q[2])) + L5*(((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2])*std::sin(q[4])*std::cos(q[1]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[3]) + (-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[2])*std::cos(q[3]))*std::cos(q[4]));
out[2] = L3*(-(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2])) - L4*((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::sin(q[3]) + L5*((-(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::cos(q[3])*std::cos(q[4]) + (((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[4]));
out[3] = -L4*(-(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + (((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3])) + L5*((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) - (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3]))*std::cos(q[4]);
out[4] = L5*((((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::cos(q[4]) - (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::sin(q[4]));
out[5] = 0;
out[6] = 0;
out[7] = L1*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0])) + L2*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1]) + L3*((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2])) - L4*((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3])) + L5*(((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + ((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::cos(q[4]) + (((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::sin(q[4]));
out[8] = -L2*(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1]) + L3*((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[2]) - L4*(-((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[3]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1])*std::cos(q[2])) + L5*((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2])*std::sin(q[4])*std::cos(q[1]) + (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[3]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[2])*std::cos(q[3]))*std::cos(q[4]));
out[9] = L3*(((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2])) - L4*(-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]))*std::sin(q[3]) + L5*((((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]))*std::cos(q[3])*std::cos(q[4]) + ((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[4]));
out[10] = -L4*(-((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + ((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3])) + L5*(((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) - (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3]))*std::cos(q[4]);
out[11] = L5*(((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::cos(q[4]) - (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::sin(q[4]));
out[12] = 0;
out[13] = 0;
out[14] = 0;
out[15] = -L2*std::cos(q[1]) + L3*std::sin(q[1])*std::cos(q[2]) - L4*(-std::sin(q[1])*std::sin(q[3])*std::cos(q[2]) + std::cos(q[1])*std::cos(q[3])) + L5*((std::sin(q[1])*std::cos(q[2])*std::cos(q[3]) + std::sin(q[3])*std::cos(q[1]))*std::cos(q[4]) - std::sin(q[1])*std::sin(q[2])*std::sin(q[4]));
out[16] = L3*std::sin(q[2])*std::cos(q[1]) + L4*std::sin(q[2])*std::sin(q[3])*std::cos(q[1]) + L5*(std::sin(q[2])*std::cos(q[1])*std::cos(q[3])*std::cos(q[4]) + std::sin(q[4])*std::cos(q[1])*std::cos(q[2]));
out[17] = -L4*(-std::sin(q[1])*std::sin(q[3]) + std::cos(q[1])*std::cos(q[2])*std::cos(q[3])) + L5*(std::sin(q[1])*std::cos(q[3]) + std::sin(q[3])*std::cos(q[1])*std::cos(q[2]))*std::cos(q[4]);
out[18] = L5*(-(std::sin(q[1])*std::sin(q[3]) - std::cos(q[1])*std::cos(q[2])*std::cos(q[3]))*std::sin(q[4]) + std::sin(q[2])*std::cos(q[1])*std::cos(q[4]));
out[19] = 0;
out[20] = 0;
}

void robot_model_baxter::EE::jacobian(const VectorXd &q, MatrixXd &out)
{
out[0] = L1*((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0])) + L2*((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1]) + L3*((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + (-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2])) - L4*((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) - (-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3])) + L5*(((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]))*std::sin(q[4]) + ((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + ((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + (-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::cos(q[4])) + L6*((((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]))*std::sin(q[4]) + ((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + ((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + (-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::cos(q[4]))*std::sin(q[5]) + (((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) + ((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + (-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3]))*std::cos(q[5]));
out[1] = -L2*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1]) + L3*(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[2]) - L4*(-(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[3]) - (-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1])*std::cos(q[2])) + L5*(((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2])*std::sin(q[4])*std::cos(q[1]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[3]) + (-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[2])*std::cos(q[3]))*std::cos(q[4])) + L6*(((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1])*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[3]))*std::cos(q[5]) + (((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2])*std::sin(q[4])*std::cos(q[1]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[3]) + (-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[2])*std::cos(q[3]))*std::cos(q[4]))*std::sin(q[5]));
out[2] = L3*(-(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2])) - L4*((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::sin(q[3]) + L5*((-(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::cos(q[3])*std::cos(q[4]) + (((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[4])) + L6*((-(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::sin(q[3])*std::cos(q[5]) + ((-(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::cos(q[3])*std::cos(q[4]) + (((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[4]))*std::sin(q[5]));
out[3] = -L4*(-(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + (((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3])) + L5*((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) - (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3]))*std::cos(q[4]) + L6*(((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) - (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3]))*std::sin(q[5])*std::cos(q[4]) + (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::cos(q[5]));
out[4] = L5*((((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::cos(q[4]) - (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::sin(q[4])) + L6*((((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::cos(q[4]) - (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::sin(q[4]))*std::sin(q[5]);
out[5] = L6*(((((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::sin(q[4]) + (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::cos(q[4]))*std::cos(q[5]) - (((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) + (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3]))*std::sin(q[5]));
out[6] = 0;
out[7] = L1*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0])) + L2*((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1]) + L3*((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2])) - L4*((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3])) + L5*(((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + ((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::cos(q[4]) + (((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::sin(q[4])) + L6*((((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + ((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::cos(q[4]) + (((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::sin(q[4]))*std::sin(q[5]) + (((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) + ((-1.0/2.0*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3]))*std::cos(q[5]));
out[8] = -L2*(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1]) + L3*((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[2]) - L4*(-((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[3]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1])*std::cos(q[2])) + L5*((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2])*std::sin(q[4])*std::cos(q[1]) + (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[3]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[2])*std::cos(q[3]))*std::cos(q[4])) + L6*((-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[3]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1])*std::cos(q[2]))*std::cos(q[5]) + ((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2])*std::sin(q[4])*std::cos(q[1]) + (-((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[3]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[2])*std::cos(q[3]))*std::cos(q[4]))*std::sin(q[5]));
out[9] = L3*(((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2])) - L4*(-((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]))*std::sin(q[3]) + L5*((((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]))*std::cos(q[3])*std::cos(q[4]) + ((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[4])) + L6*((((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]))*std::sin(q[3])*std::cos(q[5]) + ((((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]))*std::cos(q[3])*std::cos(q[4]) + ((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[4]))*std::sin(q[5]));
out[10] = -L4*(-((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + ((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) - ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3])) + L5*(((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) - (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3]))*std::cos(q[4]) + L6*((-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::cos(q[5]) + (((1.0/2.0)*M_SQRT2*std::sin(q[0]) + (1.0/2.0)*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) - (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3]))*std::sin(q[5])*std::cos(q[4]));
out[11] = L5*(((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::cos(q[4]) - (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::sin(q[4])) + L6*(((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::cos(q[4]) - (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::sin(q[4]))*std::sin(q[5]);
out[12] = L6*((((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::sin(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[2]))*std::sin(q[4]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[3])*std::cos(q[1]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::cos(q[3]))*std::cos(q[4]))*std::cos(q[5]) - ((-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::cos(q[1])*std::cos(q[3]) + (-(-1.0/2.0*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[1])*std::cos(q[2]) + ((1.0/2.0)*M_SQRT2*std::sin(q[0]) - 1.0/2.0*M_SQRT2*std::cos(q[0]))*std::sin(q[2]))*std::sin(q[3]))*std::sin(q[5]));
out[13] = 0;
out[14] = 0;
out[15] = -L2*std::cos(q[1]) + L3*std::sin(q[1])*std::cos(q[2]) - L4*(-std::sin(q[1])*std::sin(q[3])*std::cos(q[2]) + std::cos(q[1])*std::cos(q[3])) + L5*((std::sin(q[1])*std::cos(q[2])*std::cos(q[3]) + std::sin(q[3])*std::cos(q[1]))*std::cos(q[4]) - std::sin(q[1])*std::sin(q[2])*std::sin(q[4])) + L6*(((std::sin(q[1])*std::cos(q[2])*std::cos(q[3]) + std::sin(q[3])*std::cos(q[1]))*std::cos(q[4]) - std::sin(q[1])*std::sin(q[2])*std::sin(q[4]))*std::sin(q[5]) + (std::sin(q[1])*std::sin(q[3])*std::cos(q[2]) - std::cos(q[1])*std::cos(q[3]))*std::cos(q[5]));
out[16] = L3*std::sin(q[2])*std::cos(q[1]) + L4*std::sin(q[2])*std::sin(q[3])*std::cos(q[1]) + L5*(std::sin(q[2])*std::cos(q[1])*std::cos(q[3])*std::cos(q[4]) + std::sin(q[4])*std::cos(q[1])*std::cos(q[2])) + L6*((std::sin(q[2])*std::cos(q[1])*std::cos(q[3])*std::cos(q[4]) + std::sin(q[4])*std::cos(q[1])*std::cos(q[2]))*std::sin(q[5]) + std::sin(q[2])*std::sin(q[3])*std::cos(q[1])*std::cos(q[5]));
out[17] = -L4*(-std::sin(q[1])*std::sin(q[3]) + std::cos(q[1])*std::cos(q[2])*std::cos(q[3])) + L5*(std::sin(q[1])*std::cos(q[3]) + std::sin(q[3])*std::cos(q[1])*std::cos(q[2]))*std::cos(q[4]) + L6*((std::sin(q[1])*std::sin(q[3]) - std::cos(q[1])*std::cos(q[2])*std::cos(q[3]))*std::cos(q[5]) + (std::sin(q[1])*std::cos(q[3]) + std::sin(q[3])*std::cos(q[1])*std::cos(q[2]))*std::sin(q[5])*std::cos(q[4]));
out[18] = L5*(-(std::sin(q[1])*std::sin(q[3]) - std::cos(q[1])*std::cos(q[2])*std::cos(q[3]))*std::sin(q[4]) + std::sin(q[2])*std::cos(q[1])*std::cos(q[4])) + L6*(-(std::sin(q[1])*std::sin(q[3]) - std::cos(q[1])*std::cos(q[2])*std::cos(q[3]))*std::sin(q[4]) + std::sin(q[2])*std::cos(q[1])*std::cos(q[4]))*std::sin(q[5]);
out[19] = L6*(((std::sin(q[1])*std::sin(q[3]) - std::cos(q[1])*std::cos(q[2])*std::cos(q[3]))*std::cos(q[4]) + std::sin(q[2])*std::sin(q[4])*std::cos(q[1]))*std::cos(q[5]) - (-std::sin(q[1])*std::cos(q[3]) - std::sin(q[3])*std::cos(q[1])*std::cos(q[2]))*std::sin(q[5]));
out[20] = 0;
}