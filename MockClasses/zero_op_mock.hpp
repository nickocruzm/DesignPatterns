#ifndef __ZERO_OP_HPP__
#define __ZERO_OP_HPP__

#include "../Base.hpp"

class ZeroOpMock : public Base {
    public:
        ZeroOpMock(double value) : Base() { }
        virtual double evaluate() { return 0.0; }
        virtual std::string stringify() { return "0.000000"; }
};

#endif //__THREE_OP_HPP__
