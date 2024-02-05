#ifndef __SELECT_CONTAINS_HPP__
#define __SELECT_CONTAINS_HPP__

#include "select.hpp"

using std::string;

class Select_Contains : public Select_Column {
    protected:
        string theName;

    public:
        Select_Contains(const Spreadsheet* sheet, const string& colName, const string& name) : Select_Column(sheet, colName) {
            theName = name;
        }

        bool select(const Spreadsheet* sheet, int row) {
            return select(sheet->cell_data(row, column));
        }

        // Check whether the substring theName exist inside the string s
        bool select(const string& s) const {
            int a = theName.length();
            int b = s.length();
            for (int i = 0; i <= b - a; i++) {
                int j;
                for (j = 0; j < a; j++) {
                    if (s[i + j] != theName[j]) {
                        break;
                    }
                }
                if (j == a) {
                    return true;
                }
            }
            return false;
        }

};

#endif