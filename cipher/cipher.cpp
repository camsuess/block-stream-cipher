#include <iostream>
#include <string>
#include <fstream>
#include "BE.h"
#include "BD.h"

int main(int argc, char *argv[]) {

    if (argc != 6) {
        std::cout << "Error: incorrect number of arguments provided." << std::endl;
        return 1;
    }

    char cipherType;
    char modeType;


    cipherType = argv[1][0];

    if (cipherType != 'B' && cipherType != 'S'){
        std::cout << "Invalid Function Type" <<std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[2]);

    if(!inputFile){
        std::cerr <<"Input File Does Not Exist" << std::endl;
    }

    std::ofstream outputFile(argv[3]);

    if(!outputFile){
        std::cerr <<"Error With Output File" << std::endl;
        return 1;
    }

    std::ifstream keyFile(argv[4]);

    if(!keyFile) {
        std::cerr <<"Key File Does Not Exist" << std::endl;
    }

    modeType = argv[5][0];

    if(modeType != 'E' && modeType != 'D'){
        std::cout << "Invalid Mode Type" << std::endl;
    }

    //encryption or decryption starts

    BE be;
    BD bd;

    if(cipherType == 'B' && modeType == 'E') {
        //begin block encryption
        be.encrypt(inputFile, outputFile, keyFile);
    }

    if(cipherType == 'B' && modeType == 'D') {
        //begin block decryption
        bd.decrypt(inputFile, outputFile, keyFile);
    }

    if(cipherType == 'S' && modeType == 'E') {
        //begin stream encryption
    }

    if(cipherType == 'S' && modeType == 'D') {
        //begin steram decryption
    }

    inputFile.close();
    outputFile.close();
    keyFile.close();
    
    return 0;
}