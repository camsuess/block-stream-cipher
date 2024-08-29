#include "SE.h"
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void SE::encrypt(std::ifstream& input, std::ofstream& output, std::ifstream& key){

    string keyContent;
    getline(key, keyContent);

    vector<char> chars;
    string line;

    while(getline(input, line)){
        for(char c : line){
            chars.push_back(c);
        }
        chars.push_back('\n');
    }

    size_t keyLen = keyContent.length();
    size_t j = 0;
    size_t i = 0;
    string xorResult;

    while(i < chars.size() - 1){
        unsigned char result = chars[i] ^ keyContent[j];
        xorResult.push_back(result);
        i++;
        j = (j+1) % keyLen;

    }
    output << xorResult;
}   