#ifndef __NEGATIVE_TWO_OP_HPP__
#define __NEGATIVE_TWO_OP_HPP__

#include "../base.hpp"

class NegativeTwoOpMock : public Base {
    public:
        NegativeTwoOpMock(double value) : Base() { }
        virtual double evaluate() { return -2.0; }
        virtual std::string stringify() { return "-2.000000"; }
};

#endif 
