#include "spreadsheet.hpp"
#include "spreadsheet.cpp"
#include "select.hpp"
#include "Select_Contains.hpp"
#include "Select_Or.hpp"
#include "Select_And.hpp"
#include "Select_Not.hpp"

#include "gtest/gtest.h"
#include <iostream>

using std::stringstream;
using std::cout;
using std::string;

TEST(Print_Selection, print_all) {
    Spreadsheet sheet;
    sheet.set_column_names({"First", "Last" ,"Age" ,"Gender" ,"Major"});
    sheet.add_row({"Rick", "Wang", "19", "Male", "Computer Science"});
    sheet.add_row({"Nicholas", "Martinez", "19", "Male", "Computer Science"});
    sheet.add_row({"Brian", "Feng", "21", "Male", "Economics"});

    stringstream ss;
    sheet.print_selection(ss);
    string output = ss.str();
    EXPECT_EQ(output, "Rick Wang 19 Male Computer Science \nNicholas Martinez 19 Male Computer Science \nBrian Feng 21 Male Economics \n");
}

TEST(Select_Contains, Select_Contains_Empty) {
    Spreadsheet sheet;
    sheet.set_column_names({"First", "Last" ,"Age" ,"Gender" ,"Major"});
    sheet.add_row({"Rick", "Wang", "19", "Male", "Computer Science"});
    sheet.add_row({"Nicholas", "Martinez", "19", "Male", "Computer Science"});
    sheet.add_row({"Brian", "Feng", "21", "Male", "Economics"});
    sheet.add_row({"Annie", "Shao", "20", "Female", "Politics"});

    stringstream ss;
    sheet.set_selection(new Select_Contains(&sheet, "First", ""));
    sheet.print_selection(ss);
    string output = ss.str();
    EXPECT_EQ(output, "Rick Wang 19 Male Computer Science \nNicholas Martinez 19 Male Computer Science \nBrian Feng 21 Male Economics \nAnnie Shao 20 Female Politics \n");
}

TEST(Select_Contains, Select_Contains_Zero) {
    Spreadsheet sheet;
    sheet.set_column_names({"First", "Last" ,"Age" ,"Gender" ,"Major"});
    sheet.add_row({"Rick", "Wang", "19", "Male", "Computer Science"});
    sheet.add_row({"Nicholas", "Martinez", "19", "Male", "Computer Science"});
    sheet.add_row({"Brian", "Feng", "21", "Male", "Economics"});
    sheet.add_row({"Annie", "Shao", "20", "Female", "Politics"});

    stringstream ss;
    sheet.set_selection(new Select_Contains(&sheet, "Gender", "nope"));
    sheet.print_selection(ss);
    string output = ss.str();
    EXPECT_EQ(output, "");
}

TEST(Select_Contains, Select_Contains_One) {
    Spreadsheet sheet;
    sheet.set_column_names({"First", "Last" ,"Age" ,"Gender" ,"Major"});
    sheet.add_row({"Rick", "Wang", "19", "Male", "Computer Science"});
    sheet.add_row({"Nicholas", "Martinez", "19", "Male", "Computer Science"});
    sheet.add_row({"Brian", "Feng", "21", "Male", "Economics"});

    stringstream ss;
    sheet.set_selection(new Select_Contains(&sheet, "Age", "21"));
    sheet.print_selection(ss);
    string output = ss.str();
    EXPECT_EQ(output, "Brian Feng 21 Male Economics \n");
}

TEST(Select_Contains, Select_Contains_Two) {
    Spreadsheet sheet;
    sheet.set_column_names({"First", "Last" ,"Age" ,"Gender" ,"Major"});
    sheet.add_row({"Rick", "Wang", "19", "Male", "Computer Science"});
    sheet.add_row({"Nicholas", "Martinez", "19", "Male", "Computer Science"});
    sheet.add_row({"Brian", "Feng", "21", "Male", "Economics"});
    sheet.add_row({"Annie", "Shao", "20", "Female", "Politics"});

    stringstream ss;
    sheet.set_selection(new Select_Contains(&sheet, "Gender", "Male"));
    sheet.print_selection(ss);
    string output = ss.str();
    EXPECT_EQ(output, "Rick Wang 19 Male Computer Science \nNicholas Martinez 19 Male Computer Science \nBrian Feng 21 Male Economics \n");
}


TEST(Select_Not, Select_Not_Default) {
    Spreadsheet sheet;
    sheet.set_column_names({"First", "Last" ,"Age" ,"Gender" ,"Major"});
    sheet.add_row({"Rick", "Wang", "19", "Male", "Computer Science"});
    sheet.add_row({"Nicholas", "Martinez", "19", "Male", "Computer Science"});
    sheet.add_row({"Brian", "Feng", "21", "Male", "Economics"});
    sheet.add_row({"Annie", "Shao", "20", "Female", "Politics"});

    stringstream ss;
    sheet.set_selection(new Select_Not(
            new Select_Contains(&sheet, "Gender", "Male"))
    );
    sheet.print_selection(ss);
    string output = ss.str();
    EXPECT_EQ(output, "Annie Shao 20 Female Politics \n");
}

TEST(Select_Not, Select_Not_All) {
    Spreadsheet sheet;
    sheet.set_column_names({"First", "Last" ,"Age" ,"Gender" ,"Major"});
    sheet.add_row({"Rick", "Wang", "19", "Male", "Computer Science"});
    sheet.add_row({"Nicholas", "Martinez", "19", "Male", "Computer Science"});
    sheet.add_row({"Brian", "Feng", "21", "Male", "Economics"});
    sheet.add_row({"Annie", "Shao", "20", "Female", "Politics"});

    stringstream ss;
    sheet.set_selection(new Select_Not(
            new Select_Contains(&sheet, "Gender", "nope"))
    );
    sheet.print_selection(ss);
    string output = ss.str();
    EXPECT_EQ(output, "Rick Wang 19 Male Computer Science \nNicholas Martinez 19 Male Computer Science \nBrian Feng 21 Male Economics \nAnnie Shao 20 Female Politics \n");
}

TEST(Select_Not, Select_Not_None) {
    Spreadsheet sheet;
    sheet.set_column_names({"First", "Last" ,"Age" ,"Gender" ,"Major"});
    sheet.add_row({"Rick", "Wang", "19", "Male", "Computer Science"});
    sheet.add_row({"Nicholas", "Martinez", "19", "Male", "Computer Science"});
    sheet.add_row({"Brian", "Feng", "21", "Male", "Economics"});
    sheet.add_row({"Annie", "Shao", "20", "Female", "Politics"});

    stringstream ss;
    sheet.set_selection(new Select_Not(
            new Select_Contains(&sheet, "Gender", "ale"))
    );
    sheet.print_selection(ss);
    string output = ss.str();
    EXPECT_EQ(output, "");
}

TEST(Select_And, Select_And_Default) {
    Spreadsheet sheet;
    sheet.set_column_names({"First", "Last" ,"Age" ,"Gender" ,"Major"});
    sheet.add_row({"Rick", "Wang", "19", "Male", "Computer Science"});
    sheet.add_row({"Nicholas", "Martinez", "19", "Male", "Computer Science"});
    sheet.add_row({"Brian", "Feng", "21", "Male", "Economics"});
    sheet.add_row({"Annie", "Shao", "20", "Female", "Politics"});

    stringstream ss;
    sheet.set_selection(new Select_And(
            new Select_Contains(&sheet,"Age","19"),
            new Select_Contains(&sheet,"Major","Computer Science")
    ));
    sheet.print_selection(ss);
    string output = ss.str();
    EXPECT_EQ(output, "Rick Wang 19 Male Computer Science \nNicholas Martinez 19 Male Computer Science \n");
}

TEST(Select_And, Select_And_One_False) {
    Spreadsheet sheet;
    sheet.set_column_names({"First", "Last" ,"Age" ,"Gender" ,"Major"});
    sheet.add_row({"Rick", "Wang", "19", "Male", "Computer Science"});
    sheet.add_row({"Nicholas", "Martinez", "19", "Male", "Computer Science"});
    sheet.add_row({"Brian", "Feng", "21", "Male", "Economics"});
    sheet.add_row({"Annie", "Shao", "20", "Female", "Politics"});

    stringstream ss;
    sheet.set_selection(new Select_And(
            new Select_Contains(&sheet,"Age","21"),
            new Select_Contains(&sheet,"Major","Computer Science")
    ));
    sheet.print_selection(ss);
    string output = ss.str();
    EXPECT_EQ(output, "");
}

TEST(Select_And, Select_And_Empty) {
    Spreadsheet sheet;
    sheet.set_column_names({"First", "Last" ,"Age" ,"Gender" ,"Major"});
    sheet.add_row({"Rick", "Wang", "19", "Male", "Computer Science"});
    sheet.add_row({"Nicholas", "Martinez", "19", "Male", "Computer Science"});
    sheet.add_row({"Brian", "Feng", "21", "Male", "Economics"});
    sheet.add_row({"Annie", "Shao", "20", "Female", "Politics"});

    stringstream ss;
    sheet.set_selection(new Select_And(
            new Select_Contains(&sheet,"Age",""),
            new Select_Contains(&sheet,"Major","Ecology")
    ));
    sheet.print_selection(ss);
    string output = ss.str();
    EXPECT_EQ(output, "");
}

TEST(SELECT_OR, Select_Basic) {
    Spreadsheet sheet;
    sheet.set_column_names({"First", "Last" ,"Age" ,"Gender" ,"Major"});
    sheet.add_row({"Rick", "Wang", "19", "Male", "Computer Science"});
    sheet.add_row({"Nicholas", "Martinez", "19", "Male", "Computer Science"});
    sheet.add_row({"Brian", "Feng", "21", "Male", "Economics"});
    sheet.add_row({"Annie", "Shao", "20", "Female", "Politics"});

    stringstream ss;
    sheet.set_selection(
        new Select_Or(
            new Select_Contains(&sheet, "Major", "Economics"),
            new Select_Contains(&sheet, "Major", "Politics")
        )
    );

    sheet.print_selection(ss);
    string output = ss.str();
    EXPECT_EQ(output, "Brian Feng 21 Male Economics \nAnnie Shao 20 Female Politics \n");
}


TEST(SELECT_OR, NON_EXISTENT_DATA){

    Spreadsheet sheet;
    sheet.set_column_names({"First", "Last" ,"Age" ,"Gender" ,"Major"});
    sheet.add_row({"Rick", "Wang", "19", "Male", "Computer Science"});
    sheet.add_row({"Nicholas", "Martinez", "19", "Male", "Computer Science"});
    sheet.add_row({"Brian", "Feng", "21", "Male", "Economics"});
    sheet.add_row({"Annie", "Shao", "20", "Female", "Politics"});

    stringstream ss;
    sheet.set_selection(
        new Select_Or(
            new Select_Contains(&sheet, "Major", "Math"),
            new Select_Contains(&sheet, "Major", "Life")
        )
    );

    sheet.print_selection(ss);
    string output = ss.str();
    EXPECT_EQ(output, "");

}

TEST(SELCT_OR, One_doesnt_exist){

    Spreadsheet sheet;
    sheet.set_column_names({"First", "Last" ,"Age" ,"Gender" ,"Major"});
    sheet.add_row({"Rick", "Wang", "19", "Male", "Computer Science"});
    sheet.add_row({"Nicholas", "Martinez", "19", "Male", "Computer Science"});
    sheet.add_row({"Brian", "Feng", "21", "Male", "Economics"});
    sheet.add_row({"Annie", "Shao", "20", "Female", "Politics"});

    stringstream ss;
    sheet.set_selection(
        new Select_Or(
            new Select_Contains(&sheet, "First", "Rick"),
            new Select_Contains(&sheet, "First", "Sam")
        )
    );

    sheet.print_selection(ss);
    string output = ss.str();
    EXPECT_EQ(output, "Rick Wang 19 Male Computer Science \n");

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}