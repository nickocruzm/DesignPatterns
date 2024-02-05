#include <iostream>
#include <vector>
#include "Factory.hpp"
#include "base.hpp"

using namespace std;

int main(int argc, char** argv){
    Factory fac = Factory();
    Base* temp = fac.parse(argv, argc);
    if (temp != nullptr) {
        cout << "result is: " << temp->evaluate() << endl;
    }
    cout << "..Program Finished" << endl;
    return 0;
}
