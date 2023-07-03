#include <iostream>

#include "Base.hpp"
#include "Op.hpp"
#include "Mult.hpp"
#include "Div.hpp"
#include "Add.hpp"
#include "Sub.hpp"

int main() {
    Base* three = new Op(3);
    Base* seven = new Op(7);
    Base* four = new Op(4);
    Base* two = new Op(2);
    Base* mult = new Mult(seven, four);
    Base* add = new Add(three, mult);
    Base* minus = new Sub(add, two);

    std::cout << minus->stringify() << " = " << minus->evaluate() << std::endl;
    return 0;
}
