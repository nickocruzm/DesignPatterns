#include "spreadsheet.hpp"
#include "select.hpp"

#include <algorithm>
#include <iostream>

Spreadsheet::~Spreadsheet()
{
    if (select != nullptr) {
        delete select;
    }
}

void Spreadsheet::set_selection(Select* new_select)
{
    delete select;
    select = new_select;
}

void Spreadsheet::clear()
{
    column_names.clear();
    data.clear();
    delete select;
    select = nullptr;
}

void Spreadsheet::set_column_names(const std::vector<std::string>& names)
{
    column_names=names;
}

void Spreadsheet::add_row(const std::vector<std::string>& row_data)
{
    data.push_back(row_data);
}

int Spreadsheet::get_column_by_name(const std::string& name) const
{
    for(int i=0; i<column_names.size(); i++)
        if(column_names.at(i) == name)
            return i;
    return -1;
}


void Spreadsheet::print_selection(std::ostream& out) const{
    // we go through every rows one by one and see if we want to print out the contents
    // inside the row based on the select object's select function.
    for(int i = 0; i < data.size(); i++){
        for(int j = 0; j < column_names.size(); j++){
            if (select != nullptr && select->select(this, i)) {
                out<<cell_data(i,j)<<" ";
            }
        }
        if (select != nullptr && select->select(this, i)) {
            out<<std::endl;
        }
    }

    // if the select variable is still a nullptr then we output everything inside the spreadsheet
    if (select == nullptr) {
        for(int i = 0; i < data.size(); i++){
            for(int j = 0; j < column_names.size(); j++){
                out<<cell_data(i,j)<<" ";
            }
            out<<std::endl;
        }
    }


}