#ifndef __OP_HPP__
#define __OP_HPP__

#include "base.hpp"

class Op : public Base {
    private:
        // The value of this operand
        double value;

    public:
        Op(double v) : Base() {
            this->value = v;
        }

        // The value of this operand
        double evaluate() {
            return value;
        }

        std::string stringify() {
            return std::to_string(value);
        }
};

#endif //__OP_HPP__
