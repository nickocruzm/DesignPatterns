#ifndef __SELECT_NOT_HPP__
#define __SELECT_NOT_HPP__

#include "select.hpp"
#include "Select_Contains.hpp"

using std::string;

class Select_Not : public Select {
    protected:
        // pointert to the Select Contains object
        Select* select_ptr = nullptr;

    public:
        Select_Not(Select* ptr) {
            select_ptr = ptr;
        }

        ~Select_Not() {
            if (select_ptr != nullptr) {
                delete select_ptr;
            }
        }

        // inverse the
        bool select(const Spreadsheet* sheet, int row) const {
            return !(select_ptr->select(sheet, row));
        }

        // Check whether the substring theName exist inside the string s
        bool select(const string& s) const {return false;}

};

#endif