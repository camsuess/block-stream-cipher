#ifndef BD_H
#define BD_H

#include <string>
#include <fstream>

class BD {
public: 
    void decrypt(std::ifstream& input, std::ofstream& output, std::ifstream& key);
};

#endif