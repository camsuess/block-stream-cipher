#include "BE.h"
#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


void BE::encrypt(std::ifstream& input, std::ofstream& output, std::ifstream& key){

    string keyContent;
    getline(key, keyContent);

    //create vector and fill with 16 byte blocks

    vector<string> blocks;
    string buffer(16, '\0');

    while(input.read(&buffer[0], 16)){
        blocks.push_back(buffer);
    }

    int bytes = input.gcount();

    if(bytes > 0) {
        string lastBlock = buffer.substr(0, bytes);
        lastBlock.append(16 - bytes, static_cast<char>(0x81));
        blocks.push_back(lastBlock);
    }

    //output = lu��������������
    // for(const auto& block : blocks){
    //     std::cout << block << std::endl;
    // }

    //output padded blocks in hex format for verification (from chatgippity)
    // for (const auto& block : blocks) {
    //     for (unsigned char c : block) {
    //         std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(c) << ' ';
    //     }
    //     std::cout << std::endl;
    // }

    //start encryption using the blocks and key

    //XOR
    vector<std::string> xoredBlocks;
    for(const auto& block : blocks){
        size_t blockLen = 16;
        size_t keyLen = keyContent.length();
        size_t i = 0;
        size_t j = 0;
        std::string xorResult;
        while(i < blockLen) {
            //do xor
            unsigned char result = block[i] ^ keyContent[j];
            xorResult += result;
            i++;
            j = (j + 1) % keyLen;
        }
        xoredBlocks.push_back(xorResult);
    }

    //for printing xored blocks in hex format for verification
    for(const auto& block : xoredBlocks){
        for (unsigned char c : block) {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(c) << ' ';
        }
        std::cout << std::endl;
    }

    //byte swapping
    for(auto& block : xoredBlocks){
        size_t start = 0;
        size_t end = block.length() - 1;
        while(start != end){
            if(static_cast<int>(keyContent[start])  % 2 == 0){
                start++;
            } else {
                std::swap(block[start], block[end]);
                start++;
                end--;
            }
            if(start == block.length()){
                start = 0;
            }
        }
        output << block;
    }

    //for printing xored blocks in hex format for verification
    for(const auto& block : xoredBlocks){
        for (unsigned char c : block) {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(c) << ' ';
        }
        std::cout << std::endl;
    }
};