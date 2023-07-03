#ifndef __ADD_TEST_HPP__
#define __ADD_TEST_HPP__

#include "gtest/gtest.h"
#include "Add.hpp"
#include "Op.hpp"
#include "Mult.hpp"
#include "div.hpp"

TEST(AddTest,AddSimple){
	Base* op1 = new Op(2);
	Base* op2 = new Op(3);
	
	Add* add = new Add(op1,op2);
	
	EXPECT_EQ(add->evaluate(),5);

}

TEST(AddTest,AddZero){
	Base* x = new Op(0);
	Base* y = new Op(48);

	Add* add = new Add(x,y);
	
	EXPECT_EQ(add->evaluate(),48);
	EXPECT_EQ(add->stringify(),"(0.000000+48.000000)");
}

TEST(AddTest,AddNegative){
        Base* x = new Op(-15);
        Base* y = new Op(30);

        Add* add = new Add(x,y);

        EXPECT_EQ(add->evaluate(),15);
        EXPECT_EQ(add->stringify(),"(-15.000000+30.000000)");
}
TEST(AddTest,AddWithMultiplier){
        Base* x = new Op(3);
        Base* y = new Op(9);

	Base* z = new Mult(x,y);
		

        Add* add = new Add(x,z);

        EXPECT_EQ(add->evaluate(),30);
        EXPECT_EQ(add->stringify(),"(3.000000+(3.000000*9.000000))");
}

TEST(AddTest,AddWithDiv){
	Base* a = new Op(20);
	Base* b = new Op(10);

	Base* c = new Div(a,b);

	Add* add = new Add(a,c);

	EXPECT_EQ(add->evaluate(),22);
	EXPECT_EQ(add->stringify(),"(20.000000+(20.000000/10.000000))"); 

}






#endif
