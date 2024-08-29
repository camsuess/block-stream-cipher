#ifndef SD_H
#define SD_H

#include <string>
#include <fstream>

class SD {
public: 
    void decrypt(std::ifstream& input, std::ofstream& output, std::ifstream& key);
};

#endif