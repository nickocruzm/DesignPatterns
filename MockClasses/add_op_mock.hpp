#ifndef __ADD_OP_HPP__
#define __ADD_OP_HPP__

#include "../Base.hpp"

class AddOpMock : public Base {
    public:
        AddOpMock(double value) : Base() { }
        virtual double evaluate() { return 34; }
        virtual std::string stringify() { return "(20.000000+14.000000)"; }
};

#endif //__ADD_OP_HPP__
