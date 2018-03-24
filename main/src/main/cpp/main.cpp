#include "hello.h"
#include <FirstExcersice.hpp>
#include <iostream>

int main () {
    Greeter greeter;
    greeter.hello();

    std::cout << FirstExcersice().doIt()<<std::endl;

    return 0;
}
