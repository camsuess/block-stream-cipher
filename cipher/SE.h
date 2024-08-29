#ifndef SE_H
#define SE_H

#include <string>
#include <fstream>

class SE {
    public:
        void encrypt(std::ifstream& input, std::ofstream& output, std::ifstream& key);
};

#endif