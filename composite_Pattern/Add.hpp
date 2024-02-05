#ifndef __ADD_HPP__
#define __ADD_HPP__

#include "Base.hpp"
#include <iostream>

class Add: public Base{
    private:
        Base* x1;
        Base* x2;

    public:
        Add(Base* a, Base* b){
            this->x1 = a;
            this->x2 = b;
        }

        double evaluate(){
            return (x1->evaluate() + x2->evaluate());
        }

        string stringify(){
            return( "(" + x1->stringify() + "+" + x2->stringify() + ")" );
        }

};



#endif