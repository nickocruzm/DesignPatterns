#ifndef __TESTING_HPP__
#define __TESTING_HPP__


#include "div.hpp"
#include "mult.hpp"
#include "base.hpp"
#include "Add.hpp"
#include "Pow.hpp"
#include "op.hpp"
#include "Factory.hpp"

#include "gtest/gtest.h"
//Basic Addition
TEST(AddTest,AddTwoOperands){
    Factory fac = Factory();
    char* argTest[] = {"", "2", "+", "2"};
    Base* test = fac.parse(argTest, 4);
    EXPECT_EQ(4,test->evaluate());
};


//Add with Multiple Operations
TEST(AddAndSub, ThreeOperands){
    Factory fac = Factory();
    char* argTest[] = {"", "3", "+", "2", "-", "6"};
    Base* test = fac.parse(argTest, 6);
    EXPECT_EQ(-1,test->evaluate());
}

TEST(AddAndDiv, DoubleOuput){
    Factory fac = Factory();
    char* argTest[] = {"", "3", "+", "2", "/", "10"};
    Base* test = fac.parse(argTest, 6);
    EXPECT_EQ(0.5,test->evaluate());
}

TEST(AddAndPow,FiveOperands){
    Factory fac = Factory();
    char* argTest[] = {"", "3", "+", "2", "\*\*", "2"};
    Base* test = fac.parse(argTest, 6);
    EXPECT_EQ(25,test->evaluate());
}


//Basic Subtraction
TEST(SubTest,SubTwoOperands){
    Factory fac = Factory();
    char* argTest[] = {"", "2", "-", "2"};
    Base* test = fac.parse(argTest, 4);
    EXPECT_EQ(0,test->evaluate());
};

//Subtraction with multiple operations
TEST(SubMultTest,ThreeOperands){
    Factory fac = Factory();
    char* argTest[] = {"", "2", "+", "2","\*","3"};
    Base* test = fac.parse(argTest, 6);
    EXPECT_EQ(12,test->evaluate());
};

TEST(SubDivTest, ThreeOperands){
    Factory fac = Factory();
    char* argTest[] = {"", "6", "-", "2","/", "4"};
    Base* test = fac.parse(argTest, 6);
    EXPECT_EQ(1,test->evaluate());
};
TEST(SubPowTest,ThreeOperands){
    Factory fac = Factory();
    char* argTest[] = {"", "5", "-", "2","\*\*", "3"};
    Base* test = fac.parse(argTest, 6);
    EXPECT_EQ(27,test->evaluate());
};

//Basic Multiplication
TEST(MultTest, MultTwoOperand){
    Factory fac = Factory();
    char* argTest[] = {"", "3", "\*", "2"};
    Base* test = fac.parse(argTest, 4);
    EXPECT_EQ(6,test->evaluate());
};

TEST(MultTest,MultThreeOperands){
    Factory fac = Factory();
    char* argTest[] = {"", "2", "\*", "2","\*","3"};
    Base* test = fac.parse(argTest, 6);
    EXPECT_EQ(12,test->evaluate());
};

TEST(MultDivTest,ThreeOperands){
    Factory fac = Factory();
    char* argTest[] = {"", "2", "\*", "2","/","1"};
    Base* test = fac.parse(argTest, 6);
    EXPECT_EQ(4,test->evaluate());
};

TEST(MultPowTest,ThreeOperands){
    Factory fac = Factory();
    char* argTest[] = {"", "2", "\*", "3","\*\*","2"};
    Base* test = fac.parse(argTest, 6);
    EXPECT_EQ(36,test->evaluate());

};




//Basic Division
TEST(DivTest, DivTwoOperands){
    Factory fac = Factory();
    char* argTest[] = {"", "2", "/", "2"};
    Base* test = fac.parse(argTest, 4);
    EXPECT_EQ(1,test->evaluate());
};

//Basic Power
TEST(PowTest, PowTwoOperands){
    Factory fac = Factory();
    char* argTest[] = {"", "3", "\*\*", "2"};
    Base* test = fac.parse(argTest, 4);
    EXPECT_EQ(9,test->evaluate());
};

//PowOfZero
TEST(PowTest, ZeroPower){
    Factory fac = Factory();
    char* argTest[] = {"", "3", "\*\*", "0"};
    Base* test = fac.parse(argTest, 4);
    EXPECT_EQ(1,test->evaluate());
};

//chaos

TEST(Chaos, FiveOperands){
    Factory fac = Factory();
    char* argTest[] = {"", "3","\*\*","2", "+" ,"3", "/", "4", "\*" , "2"};
    Base* test = fac.parse(argTest,10);
    EXPECT_EQ(6,test->evaluate());

};



#endif