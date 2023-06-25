#ifndef __THREE_OP_HPP__
#define __THREE_OP_HPP__

#include "../base.hpp"

class ThreeOpMock : public Base {
    public:
        ThreeOpMock(double value) : Base() { }
        virtual double evaluate() { return 3.0; }
        virtual std::string stringify() { return "3.000000"; }
};

#endif //__THREE_OP_HPP__
