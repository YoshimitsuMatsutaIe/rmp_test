import numpy as np
from math import cos as c
from math import sin as s
from math import tan as t
from math import sqrt as sq
from base import Base
class JRz(Base):
    def jrz_W0(self, q):
        return np.array([[0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0]])
    def jrz_BR(self, q):
        return np.array([[0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0]])
    def jrz_0(self, q):
        return np.array([[0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0]])
    def jrz_1(self, q):
        return np.array([[-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]), 0, 0, 0, 0, 0, 0], [0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]), 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0, 0]])
    def jrz_2(self, q):
        return np.array([[(0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[1, 0]), -(0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0]), 0, 0, 0, 0, 0], [(0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*c(q[1, 0]), -(-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0]), 0, 0, 0, 0, 0], [0, -c(q[1, 0]), 0, 0, 0, 0, 0]])
    def jrz_3(self, q):
        return np.array([[(-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]), (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0])*c(q[1, 0]), (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) - (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]), 0, 0, 0, 0], [(0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]), (-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0])*c(q[1, 0]), (-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) - (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]), 0, 0, 0, 0], [0, -s(q[1, 0])*s(q[2, 0]), c(q[1, 0])*c(q[2, 0]), 0, 0, 0, 0]])
    def jrz_4(self, q):
        return np.array([[(0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[1, 0])*c(q[3, 0]) + ((-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*s(q[3, 0]), (-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0])*c(q[2, 0]) - (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[3, 0]), (-(-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]))*s(q[3, 0]), -(0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0]) + (-(0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*c(q[3, 0]), 0, 0, 0], [(0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*c(q[1, 0])*c(q[3, 0]) + ((-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*s(q[3, 0]), -(-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[3, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0])*c(q[2, 0]), ((0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]) - (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]))*s(q[3, 0]), -(-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0]) + (-(-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*c(q[3, 0]), 0, 0, 0], [0, s(q[1, 0])*s(q[3, 0])*c(q[2, 0]) - c(q[1, 0])*c(q[3, 0]), s(q[2, 0])*s(q[3, 0])*c(q[1, 0]), s(q[1, 0])*s(q[3, 0]) - c(q[1, 0])*c(q[2, 0])*c(q[3, 0]), 0, 0, 0]])
    def jrz_5(self, q):
        return np.array([[((-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]))*c(q[4, 0]) + (-(-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0]) - ((-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*c(q[3, 0]))*s(q[4, 0]), (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0])*c(q[1, 0])*c(q[4, 0]) + ((-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[3, 0]) - (-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[1, 0])*c(q[2, 0])*c(q[3, 0]))*s(q[4, 0]), -(-(-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]))*s(q[4, 0])*c(q[3, 0]) + ((0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) - (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*c(q[4, 0]), (-(-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[1, 0])*c(q[3, 0]) + (-(0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*s(q[3, 0]))*s(q[4, 0]), -((0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]))*s(q[4, 0]) + ((0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0]) - (-(0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*c(q[3, 0]))*c(q[4, 0]), 0, 0], [(-(-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0]) - ((-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*c(q[3, 0]))*s(q[4, 0]) + ((0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]))*c(q[4, 0]), (-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0])*c(q[1, 0])*c(q[4, 0]) + ((0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[3, 0]) - (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[1, 0])*c(q[2, 0])*c(q[3, 0]))*s(q[4, 0]), -((0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]) - (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]))*s(q[4, 0])*c(q[3, 0]) + ((-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) - (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*c(q[4, 0]), (-(0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[1, 0])*c(q[3, 0]) + (-(-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*s(q[3, 0]))*s(q[4, 0]), -((-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]))*s(q[4, 0]) + ((-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0]) - (-(-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*c(q[3, 0]))*c(q[4, 0]), 0, 0], [0, (-s(q[1, 0])*c(q[2, 0])*c(q[3, 0]) - s(q[3, 0])*c(q[1, 0]))*s(q[4, 0]) - s(q[1, 0])*s(q[2, 0])*c(q[4, 0]), -s(q[2, 0])*s(q[4, 0])*c(q[1, 0])*c(q[3, 0]) + c(q[1, 0])*c(q[2, 0])*c(q[4, 0]), (-s(q[1, 0])*c(q[3, 0]) - s(q[3, 0])*c(q[1, 0])*c(q[2, 0]))*s(q[4, 0]), (-s(q[1, 0])*s(q[3, 0]) + c(q[1, 0])*c(q[2, 0])*c(q[3, 0]))*c(q[4, 0]) - s(q[2, 0])*s(q[4, 0])*c(q[1, 0]), 0, 0]])
    def jrz_6(self, q):
        return np.array([[(((-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]))*s(q[4, 0]) + ((-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0]) + ((-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*c(q[3, 0]))*c(q[4, 0]))*s(q[5, 0]) + ((0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[1, 0])*c(q[3, 0]) + ((-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*s(q[3, 0]))*c(q[5, 0]), ((-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0])*c(q[2, 0]) - (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[3, 0]))*c(q[5, 0]) + ((0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0])*s(q[4, 0])*c(q[1, 0]) + (-(-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[3, 0]) + (-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[1, 0])*c(q[2, 0])*c(q[3, 0]))*c(q[4, 0]))*s(q[5, 0]), (-(-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]))*s(q[3, 0])*c(q[5, 0]) + ((-(-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]))*c(q[3, 0])*c(q[4, 0]) + ((0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) - (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*s(q[4, 0]))*s(q[5, 0]), ((-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[1, 0])*c(q[3, 0]) - (-(0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*s(q[3, 0]))*s(q[5, 0])*c(q[4, 0]) + (-(0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0]) + (-(0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*c(q[3, 0]))*c(q[5, 0]), (((0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]))*c(q[4, 0]) - (-(0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0]) + (-(0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*c(q[3, 0]))*s(q[4, 0]))*s(q[5, 0]), (((0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]))*s(q[4, 0]) + (-(0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0]) + (-(0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*c(q[3, 0]))*c(q[4, 0]))*c(q[5, 0]) - ((0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*c(q[1, 0])*c(q[3, 0]) + (-(0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*s(q[3, 0]))*s(q[5, 0]), 0], [(((-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0]) + ((-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*c(q[3, 0]))*c(q[4, 0]) + ((0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]))*s(q[4, 0]))*s(q[5, 0]) + ((0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*c(q[1, 0])*c(q[3, 0]) + ((-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*s(q[3, 0]))*c(q[5, 0]), (-(-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[3, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0])*c(q[2, 0]))*c(q[5, 0]) + ((-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0])*s(q[4, 0])*c(q[1, 0]) + (-(0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[3, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[1, 0])*c(q[2, 0])*c(q[3, 0]))*c(q[4, 0]))*s(q[5, 0]), ((0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]) - (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]))*s(q[3, 0])*c(q[5, 0]) + (((0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]) - (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]))*c(q[3, 0])*c(q[4, 0]) + ((-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) - (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*s(q[4, 0]))*s(q[5, 0]), (-(-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0]) + (-(-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*c(q[3, 0]))*c(q[5, 0]) + ((0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[1, 0])*c(q[3, 0]) - (-(-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*s(q[3, 0]))*s(q[5, 0])*c(q[4, 0]), (((-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]))*c(q[4, 0]) - (-(-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0]) + (-(-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*c(q[3, 0]))*s(q[4, 0]))*s(q[5, 0]), (((-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]))*s(q[4, 0]) + (-(-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0]) + (-(-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*c(q[3, 0]))*c(q[4, 0]))*c(q[5, 0]) - ((-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*c(q[1, 0])*c(q[3, 0]) + (-(-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*s(q[3, 0]))*s(q[5, 0]), 0], [0, ((s(q[1, 0])*c(q[2, 0])*c(q[3, 0]) + s(q[3, 0])*c(q[1, 0]))*c(q[4, 0]) - s(q[1, 0])*s(q[2, 0])*s(q[4, 0]))*s(q[5, 0]) + (s(q[1, 0])*s(q[3, 0])*c(q[2, 0]) - c(q[1, 0])*c(q[3, 0]))*c(q[5, 0]), (s(q[2, 0])*c(q[1, 0])*c(q[3, 0])*c(q[4, 0]) + s(q[4, 0])*c(q[1, 0])*c(q[2, 0]))*s(q[5, 0]) + s(q[2, 0])*s(q[3, 0])*c(q[1, 0])*c(q[5, 0]), (s(q[1, 0])*s(q[3, 0]) - c(q[1, 0])*c(q[2, 0])*c(q[3, 0]))*c(q[5, 0]) + (s(q[1, 0])*c(q[3, 0]) + s(q[3, 0])*c(q[1, 0])*c(q[2, 0]))*s(q[5, 0])*c(q[4, 0]), (-(s(q[1, 0])*s(q[3, 0]) - c(q[1, 0])*c(q[2, 0])*c(q[3, 0]))*s(q[4, 0]) + s(q[2, 0])*c(q[1, 0])*c(q[4, 0]))*s(q[5, 0]), ((s(q[1, 0])*s(q[3, 0]) - c(q[1, 0])*c(q[2, 0])*c(q[3, 0]))*c(q[4, 0]) + s(q[2, 0])*s(q[4, 0])*c(q[1, 0]))*c(q[5, 0]) - (-s(q[1, 0])*c(q[3, 0]) - s(q[3, 0])*c(q[1, 0])*c(q[2, 0]))*s(q[5, 0]), 0]])
    def jrz_ee(self, q):
        return np.array([[(((-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]))*s(q[4, 0]) + ((-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0]) + ((-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*c(q[3, 0]))*c(q[4, 0]))*s(q[5, 0]) + ((0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[1, 0])*c(q[3, 0]) + ((-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*s(q[3, 0]))*c(q[5, 0]), ((-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0])*c(q[2, 0]) - (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[3, 0]))*c(q[5, 0]) + ((0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0])*s(q[4, 0])*c(q[1, 0]) + (-(-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[3, 0]) + (-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[1, 0])*c(q[2, 0])*c(q[3, 0]))*c(q[4, 0]))*s(q[5, 0]), (-(-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]))*s(q[3, 0])*c(q[5, 0]) + ((-(-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]))*c(q[3, 0])*c(q[4, 0]) + ((0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) - (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*s(q[4, 0]))*s(q[5, 0]), ((-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[1, 0])*c(q[3, 0]) - (-(0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*s(q[3, 0]))*s(q[5, 0])*c(q[4, 0]) + (-(0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0]) + (-(0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*c(q[3, 0]))*c(q[5, 0]), (((0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]))*c(q[4, 0]) - (-(0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0]) + (-(0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*c(q[3, 0]))*s(q[4, 0]))*s(q[5, 0]), (((0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]))*s(q[4, 0]) + (-(0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0]) + (-(0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*c(q[3, 0]))*c(q[4, 0]))*c(q[5, 0]) - ((0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*c(q[1, 0])*c(q[3, 0]) + (-(0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*s(q[3, 0]))*s(q[5, 0]), 0], [(((-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0]) + ((-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*c(q[3, 0]))*c(q[4, 0]) + ((0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]))*s(q[4, 0]))*s(q[5, 0]) + ((0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*c(q[1, 0])*c(q[3, 0]) + ((-0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*s(q[3, 0]))*c(q[5, 0]), (-(-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[3, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0])*c(q[2, 0]))*c(q[5, 0]) + ((-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0])*s(q[4, 0])*c(q[1, 0]) + (-(0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[3, 0]) + (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[1, 0])*c(q[2, 0])*c(q[3, 0]))*c(q[4, 0]))*s(q[5, 0]), ((0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]) - (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]))*s(q[3, 0])*c(q[5, 0]) + (((0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]) - (0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]))*c(q[3, 0])*c(q[4, 0]) + ((-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) - (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*s(q[4, 0]))*s(q[5, 0]), (-(-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0]) + (-(-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*c(q[3, 0]))*c(q[5, 0]) + ((0.5*sq(2)*s(q[0, 0]) + 0.5*sq(2)*c(q[0, 0]))*c(q[1, 0])*c(q[3, 0]) - (-(-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*s(q[3, 0]))*s(q[5, 0])*c(q[4, 0]), (((-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]))*c(q[4, 0]) - (-(-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0]) + (-(-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*c(q[3, 0]))*s(q[4, 0]))*s(q[5, 0]), (((-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*s(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*c(q[2, 0]))*s(q[4, 0]) + (-(-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[3, 0])*c(q[1, 0]) + (-(-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*c(q[3, 0]))*c(q[4, 0]))*c(q[5, 0]) - ((-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*c(q[1, 0])*c(q[3, 0]) + (-(-0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[1, 0])*c(q[2, 0]) + (0.5*sq(2)*s(q[0, 0]) - 0.5*sq(2)*c(q[0, 0]))*s(q[2, 0]))*s(q[3, 0]))*s(q[5, 0]), 0], [0, ((s(q[1, 0])*c(q[2, 0])*c(q[3, 0]) + s(q[3, 0])*c(q[1, 0]))*c(q[4, 0]) - s(q[1, 0])*s(q[2, 0])*s(q[4, 0]))*s(q[5, 0]) + (s(q[1, 0])*s(q[3, 0])*c(q[2, 0]) - c(q[1, 0])*c(q[3, 0]))*c(q[5, 0]), (s(q[2, 0])*c(q[1, 0])*c(q[3, 0])*c(q[4, 0]) + s(q[4, 0])*c(q[1, 0])*c(q[2, 0]))*s(q[5, 0]) + s(q[2, 0])*s(q[3, 0])*c(q[1, 0])*c(q[5, 0]), (s(q[1, 0])*s(q[3, 0]) - c(q[1, 0])*c(q[2, 0])*c(q[3, 0]))*c(q[5, 0]) + (s(q[1, 0])*c(q[3, 0]) + s(q[3, 0])*c(q[1, 0])*c(q[2, 0]))*s(q[5, 0])*c(q[4, 0]), (-(s(q[1, 0])*s(q[3, 0]) - c(q[1, 0])*c(q[2, 0])*c(q[3, 0]))*s(q[4, 0]) + s(q[2, 0])*c(q[1, 0])*c(q[4, 0]))*s(q[5, 0]), ((s(q[1, 0])*s(q[3, 0]) - c(q[1, 0])*c(q[2, 0])*c(q[3, 0]))*c(q[4, 0]) + s(q[2, 0])*s(q[4, 0])*c(q[1, 0]))*c(q[5, 0]) - (-s(q[1, 0])*c(q[3, 0]) - s(q[3, 0])*c(q[1, 0])*c(q[2, 0]))*s(q[5, 0]), 0]])
