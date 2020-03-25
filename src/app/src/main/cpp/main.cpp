/*
 * A simple hello world application. Uses a library to tokenize and join a string and prints the result.
 */
#include <iostream>

#include "hello.h"
#include <FirstExcersice.hpp>

int main() {

    Greeter greeter;
    greeter.hello();

    std::cout << FirstExcersice().doIt()<<std::endl;
    auto lambda = [](auto x){ return x; };
    std::cout << lambda("Hello generic lambda!\n");


    return 0;
}
