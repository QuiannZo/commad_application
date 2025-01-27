#include <iostream>
#include <string>
#include <fstream>

#ifndef USUARIO_HPP
#define USUARIO_HPP

class Logic {
private:
public:
    Logic();
    ~Logic();
    std::string getData(std::string dataPath);
}

#endif