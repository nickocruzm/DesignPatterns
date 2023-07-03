#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "Base.hpp"

using namespace std;

class Sub: public Base{

    private:
        Base* s1;
        Base* s2;

    public:
        Sub(Base* a, Base* b){
            this->s1 = a;
            this->s2 = b;
        }
        double evaluate(){
            return(s1->evaluate() - s2->evaluate() );
        }

        string stringify(){
            return("(" + s1->stringify() + "-" + s2->stringify() + ")");
        }


};


#endif