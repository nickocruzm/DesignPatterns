#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "Base.hpp"

using std::string;

class Div : public Base {
    private:
        // The pointer to operand 1
        Base* b1;
        // The pointer to operand 2
        Base* b2;
    
    public:    
        Div(Base* b1, Base* b2) {
            this->b1 = b1;
            this->b2 = b2;
        }

        double evaluate() {
            if (b2->evaluate() == 0) {
                std::cerr << "Error: Attempted to divide by Zero.\n";
                exit(EXIT_FAILURE);
            }
            return (b1->evaluate() / b2->evaluate());
        }

        string stringify() {
            string result = "(" + b1->stringify() + "/" + b2->stringify() + ")";
            return result;
        }


};

#endif //__MULT_HPP__