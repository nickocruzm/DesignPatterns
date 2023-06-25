#ifndef __SELECT_OR_HPP__
#define __SELECT_OR_HPP__

#include "select.hpp"
#include "Select_Contains.hpp"

using std::string;

class Select_Or : public Select {
    protected:
        // pointert to the Select Contains object
        Select* select_ptrA = nullptr;
        Select* select_ptrB = nullptr;
    public:
        Select_Or(Select* ptr, Select* ptr2) {
            select_ptrA = ptr;
            select_ptrB = ptr2;
        }

        ~Select_Or() {
            if (select_ptrA != nullptr) {
                delete select_ptrA;
            }
            if (select_ptrB != nullptr) {
                delete select_ptrB;
            }
        }

        // inverse the
        bool select(const Spreadsheet* sheet, int row) const {
            return (select_ptrA->select(sheet, row) || select_ptrB->select(sheet,row));
        }

        // Check whether the substring theName exist inside the string s
        bool select(const string& s) const {return false;}

};

#endif