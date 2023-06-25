#ifndef __EIGHT_OP_HPP__
#define __EIGHT_OP_HPP__

#include "../base.hpp"

class EightOpMock : public Base {
    public:
        EightOpMock(double value) : Base() { }
        virtual double evaluate() { return 8.0; }
        virtual std::string stringify() { return "8.000000"; }
};

#endif //__EIGHT_OP_HPP__
