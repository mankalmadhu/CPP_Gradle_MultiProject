#include "hello.h"
#include <FirstExcersice.hpp>
#include <iostream>

int main () {
    Greeter greeter;
    greeter.hello();

    std::cout << FirstExcersice().doIt()<<std::endl;
    auto lambda = [](auto x){ return x; };
    std::cout << lambda("Hello generic lambda!\n");

    return 0;
}
