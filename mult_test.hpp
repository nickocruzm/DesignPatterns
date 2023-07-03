#ifndef __MULT_TEST_HPP__
#define __MULT_TEST_HPP__

#include "gtest/gtest.h"
#include "Mult.hpp"
#include "MockClasses/eight_op_mock.hpp"
#include "MockClasses/three_op_mock.hpp"
#include "MockClasses/zero_op_mock.hpp"
#include "MockClasses/negative_two_op_mock.hpp"
#include "MockClasses/add_op_mock.hpp"

TEST(MultTest, MultEvaluateOperands) {
    Base* op1 = new EightOpMock(0);
    Base* op2 = new ThreeOpMock(0);    
    Mult* mult = new Mult(op1, op2);
    EXPECT_DOUBLE_EQ(mult->evaluate(), 24);
    EXPECT_EQ(mult->stringify(), "(8.000000*3.000000)");
}

TEST(MultTest, MultEvaluateZeros) {
    Base* op1 = new EightOpMock(0);
    Base* op2 = new ZeroOpMock(0);    
    Mult* mult = new Mult(op1, op2);
    EXPECT_DOUBLE_EQ(mult->evaluate(), 0);
    EXPECT_EQ(mult->stringify(), "(8.000000*0.000000)");
}

TEST(MultTest, MultEvaluateNegatives) {
    Base* op1 = new EightOpMock(0);
    Base* op2 = new NegativeTwoOpMock(0);    
    Mult* mult = new Mult(op1, op2);
    EXPECT_DOUBLE_EQ(mult->evaluate(), -16);
    EXPECT_EQ(mult->stringify(), "(8.000000*-2.000000)");
}

TEST(MultTest, MultEvaluateAdd) {
    Base* op1 = new EightOpMock(0);
    Base* op2 = new AddOpMock(0);   
    Mult* mult = new Mult(op1, op2);
    EXPECT_DOUBLE_EQ(mult->evaluate(), 272);
    EXPECT_EQ(mult->stringify(), "(8.000000*(20.000000+14.000000))");
}

#endif //__MULT_TEST_HPP__