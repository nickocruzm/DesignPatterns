#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "op.hpp"

class Random: public Base{
    private:
        double rVal;
    public:
        Random() : Base() { 
            this->rVal = double(rand() % 100); 
        };

        double evaluate() {
            return rVal;
        }

        std::string stringify() {
            return std::to_string(rVal);
        }
        
};

#endif