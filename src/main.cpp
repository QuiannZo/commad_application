#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Logic.hpp"

int main(){
    Logic* logic = new Logic();
    std::string test = logic->getData("data/arch.csv");
    std::cout << test << std::endl;
    return 0;
}