#ifndef BE_H
#define BE_H

#include <string>
#include <fstream>

class BE {
public: 
    void encrypt(std::ifstream& input, std::ofstream& output, std::ifstream& key);
};

#endif
