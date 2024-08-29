#include "SE.h"
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void SE::encrypt(std::ifstream& input, std::ofstream& output, std::ifstream& key){

    string keyContent;
    getline(key, keyContent);

    size_t keyLen = keyContent.length();
    string line;
    size_t j = 0;

    while(getline(input, line)){
        size_t inputLen = line.length();
        string xorResult;
        size_t i = 0;

        while(i < inputLen){
            unsigned char result = line[i] ^ keyContent[j];
            xorResult.push_back(result);
            i++;
            j = (j+1) % keyLen;
        }
        output << xorResult;
    }

}   