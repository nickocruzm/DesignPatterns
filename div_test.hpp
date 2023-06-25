#ifndef __DIV_TEST_HPP__
#define __DIV_TEST_HPP__

#include "gtest/gtest.h"
#include "div.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "MockClasses/add_op_mock.hpp"

TEST(DivTest, DivEvaluateOperands) {
    Base* op1 = new Op(9);
    Base* op2 = new Op(3);    
    Div* div = new Div(op1, op2);
    EXPECT_DOUBLE_EQ(div->evaluate(), 3);
    EXPECT_EQ(div->stringify(), "(9.000000/3.000000)");
}

TEST(DivTest, DivEvaluateZeros) {
    Base* op1 = new Op(5);
    Base* op2 = new Op(0);    
    Div* div = new Div(op1, op2);
    ASSERT_EXIT(div->evaluate(), ::testing::ExitedWithCode(EXIT_FAILURE), "Error: Attempted to divide by Zero.\n");
    EXPECT_EQ(div->stringify(), "(5.000000/0.000000)");
}

TEST(DivTest, DivEvaluateNegatives) {
    Base* op1 = new Op(8);
    Base* op2 = new Op(-2);    
    Div* div = new Div(op1, op2);
    EXPECT_DOUBLE_EQ(div->evaluate(), -4);
    EXPECT_EQ(div->stringify(), "(8.000000/-2.000000)");
}

TEST(DivTest, DivEvaluateAdd) {
    Base* op1 = new Op(51);
    Base* op2 = new AddOpMock(0);   
    Div* div = new Div(op1, op2);
    EXPECT_DOUBLE_EQ(div->evaluate(), 1.5);
    EXPECT_EQ(div->stringify(), "(51.000000/(20.000000+14.000000))");
}

TEST(DivTest, DivEvaluateMult) {
    Base* op1 = new Op(61.992);
    Base* op2 = new Op(3.15);
    Base* op3 = new Op(2.4);
    Base* op4 = new Mult(op2, op3);   
    Div* div = new Div(op1, op4);
    EXPECT_DOUBLE_EQ(div->evaluate(), 8.2);
    EXPECT_EQ(div->stringify(), "(61.992000/(3.150000*2.400000))");
}

#endif
