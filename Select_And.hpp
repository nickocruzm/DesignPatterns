#ifndef __SELECT_AND_HPP__
#define __SELECT_AND_HPP__

#include "select.hpp"
#include "Select_Contains.hpp"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class Select_And : public Select {
    protected:
        // pointert to the Select Contains object
        Select* select_ptrA = nullptr;
        Select* select_ptrB = nullptr;
    public:
        Select_And(Select* ptr, Select* ptr2) {
            select_ptrA = ptr;
            select_ptrB = ptr2;

        }

        ~Select_And() {
            if (select_ptrA != nullptr) {
                delete select_ptrA;
            }
            if (select_ptrB != nullptr) {
                delete select_ptrB;
            }
        }

        bool select(const Spreadsheet* sheet, int row) const {
            // cout << select_ptrA->select(sheet, row) << " ";
            // cout << select_ptrB->select(sheet, row) << endl;

            return (select_ptrA->select(sheet, row) && select_ptrB->select(sheet,row));
        }

        // Check whether the substring theName exist inside the string s
        bool select(const string& s) const {return false;}

};

#endif