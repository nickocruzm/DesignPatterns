#ifndef __FACTORY_HPP__
#define __FACTORY_HPP__

#include <vector>
#include <iostream>
#include "base.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "Add.hpp"
#include "Sub.hpp"
#include "Pow.hpp"

using namespace std;

class Factory {
    private:
        vector<string> optrs;
        vector<Base*> operands;
        vector<Base*> operators;

    public:
        Factory() { }
         
        ~Factory() {
            for (int i = 0; i < operands.size(); i++) {
                delete operands.at(i);
            }
            for (int i = 0; i < operators.size(); i++) {
                delete operators.at(i);
            }
        }

       Base* parse(char** input, int length) {
            for (int i = 1; i < length; i++) {
                string temp = input[i];
                if (temp != "+" && temp != "-" && temp != "*" && temp != "/" && temp != "**") {
                    operands.push_back(new Op(stod(temp)));
                } else {
                    optrs.push_back(temp);
                }
            }

            if (optrs.size() != operands.size() - 1) {
                cerr << "\nInvalid Input!!"  << endl;
                return nullptr;
            }

            if (optrs.size() >= 1) {
                if (optrs.at(0) == "+") {
                    Base* add = new Add(operands.at(0), operands.at(1));
                    operators.push_back(add);
                } else if (optrs.at(0) == "-") {
                    Base* sub = new Sub(operands.at(0), operands.at(1));
                    operators.push_back(sub);
                } else if (optrs.at(0) == "*") {
                    Base* mult = new Mult(operands.at(0), operands.at(1));
                    operators.push_back(mult);
                } else if (optrs.at(0) == "/") {
                    Base* div = new Div(operands.at(0), operands.at(1));
                    operators.push_back(div);
                } else if (optrs.at(0) == "**") {
                    Base* pow = new Pow(operands.at(0), operands.at(1));
                    operators.push_back(pow);
                }
            }

            // index of the operators
            int j = 1;
            // index of the operands
            int i = 2;
            while (j < optrs.size()) {
                if (optrs.at(j) == "+") {
                    Base* add = new Add(operators.at(j - 1), operands.at(i));
                    operators.push_back(add);
                } else if (optrs.at(j) == "-") {
                    Base* sub = new Sub(operators.at(j - 1), operands.at(i));
                    operators.push_back(sub);
                } else if (optrs.at(j) == "*") {
                    Base* mult = new Mult(operators.at(j - 1), operands.at(i));
                    operators.push_back(mult);
                } else if (optrs.at(j) == "/") {
                    Base* div = new Div(operators.at(j - 1), operands.at(i));
                    operators.push_back(div);
                } else if (optrs.at(j) == "**") {
                    Base* pow = new Pow(operators.at(j - 1), operands.at(i));
                    operators.push_back(pow);
                }
                j++;
                i++;
            }

            if (operators.size() != 0) {
                return operators.at(operators.size() - 1);
            } else {
                return nullptr;
            }
        }

};      

#endif
