#ifndef __SUB_TEST_HPP__
#define __SUB_TEST_HPP__

#include "gtest/gtest.h"
#include "op.hpp"
#include "mult.hpp"
#include "MockClasses/eight_op_mock.hpp"
#include "MockClasses/three_op_mock.hpp"
#include "MockClasses/zero_op_mock.hpp"
#include "MockClasses/negative_two_op_mock.hpp"
#include "MockClasses/add_op_mock.hpp"
#include "Sub.hpp"
#include "Add.hpp"


TEST(SubTest, SubEvaluateOperands) {
    Base* op1 = new Op(9);
    Base* op2 = new Op(3); 
    Sub* sub = new Sub(op1, op2);
    EXPECT_DOUBLE_EQ(sub->evaluate(), 6);
    EXPECT_EQ(sub->stringify(), "(9.000000-3.000000)");
}

TEST(SubTest, SubEvaluateZeros) {
    Base* op1 = new Op(5);
    Base* op2 = new Op(0);     
    Sub* sub = new Sub(op1, op2);
    EXPECT_DOUBLE_EQ(sub->evaluate(), 5);
    EXPECT_EQ(sub->stringify(), "(5.000000-0.000000)");
}

TEST(SubTest, SubEvaluateNegatives) {
    Base* op1 = new Op(8);
    Base* op2 = new Op(-2);   
    Sub* sub = new Sub(op1, op2);
    EXPECT_DOUBLE_EQ(sub->evaluate(), 10);
    EXPECT_EQ(sub->stringify(), "(8.000000--2.000000)");
}

TEST(SubTest, SubEvaluateAdd) {
    Base* op1 = new Op(8);
    Base* op2 = new Op(20);
    Base* op3 = new Op(14);
    Base* add = new Add(op2, op3);   
    Sub* sub = new Sub(add, op1);
    EXPECT_DOUBLE_EQ(sub->evaluate(), 26);
    EXPECT_EQ(sub->stringify(), "((20.000000+14.000000)-8.000000)");
}

#endif //__MULT_TEST_HPP__