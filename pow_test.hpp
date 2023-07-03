#ifndef __POW_TEST_HPP__
#define __POW_TEST_HPP__

#include "gtest/gtest.h"
#include "div.hpp"
#include "Op.hpp"
#include "Mult.hpp"
#include "Pow.hpp"

TEST(PowTest, PowEvaluateOperands) {
    Base* op1 = new Op(9);
    Base* op2 = new Op(3);    
    Pow* pow = new Pow(op1, op2);
    EXPECT_DOUBLE_EQ(pow->evaluate(), 729);
    EXPECT_EQ(pow->stringify(), "(9.000000**3.000000)");
}

TEST(PowTest, PowEvaluateZeros) {
    Base* op1 = new Op(5);
    Base* op2 = new Op(0);    
    Pow* pow = new Pow(op1, op2);
    EXPECT_DOUBLE_EQ(pow->evaluate(), 1);
    EXPECT_EQ(pow->stringify(), "(5.000000**0.000000)");
}

TEST(PowTest, PowEvaluateNegatives) {
    Base* op1 = new Op(-8);
    Base* op2 = new Op(2);    
    Pow* pow = new Pow(op1, op2);
    EXPECT_DOUBLE_EQ(pow->evaluate(), 64);
    EXPECT_EQ(pow->stringify(), "(-8.000000**2.000000)");
}

TEST(PowTest, PowEvaluateMult) {
    Base* op1 = new Op(3);
    Base* op2 = new Op(4);
    Base* op3 = new Op(2);
    Base* op4 = new Mult(op2, op3);   
    Pow* pow = new Pow(op4, op1);
    EXPECT_DOUBLE_EQ(pow->evaluate(), 512);
    EXPECT_EQ(pow->stringify(), "((4.000000*2.000000)**3.000000)");
}

#endif
