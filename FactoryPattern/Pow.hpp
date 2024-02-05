#ifndef __POW_HPP__
#define __POW_HPP__

#include "base.hpp"

using namespace std;

class Pow: public Base{
    private:
        Base* num;
        Base* exp;

    public:
        Pow(Base* n, Base* e) {
            this->num = n;
            this->exp = e;
        }

        double evaluate() {
            int result = num->evaluate();

            int i = int(exp->evaluate());
            if(i == 1) {
                return num->evaluate();
            } else if(i == 0) {
                return 1;
            } else{
                while (i > 1) {
                    result = result * num->evaluate();
                    i--;
                }
            }

            return result;
  
        }

        string stringify(){
            return("(" + num->stringify() + "**" + exp->stringify() + ")" );
        }

};

#endif