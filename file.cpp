// Created on 07-May-25
//

#include "file.h"
#include "fstream"
#include "vector"
#include "iostream"

//checks if file exists by trying to open it as input file,if not then creates one.
void fileExists(const std::string &fileName) {
    std::ifstream iFile(fileName);
    if (!iFile.good()) {
        std::ofstream newFile(fileName);
        std::cout << "New File Created" << std::endl;
        newFile.close();
    } else std::cout << fileName << " file already exists" << std::endl;
}

bool writeFile(int arr[], int size, const std::string &fileName) {
    bool success = false;

    std::ofstream outputFile(fileName);
    if (outputFile.is_open()) {
        for (int i = 0; i < size; i++) {
            outputFile << arr[i] << std::endl;
        }
        outputFile.close();
        success = true;
    }

    return success;
}

std::vector<int> readFile(std::string fileName) {
    std::vector<int> v; //vector cause we dont know array length;

    std::ifstream inputFile(fileName);
    std::string s;
    while (getline(inputFile, s)) {
        int num = stoi(s);
        v.push_back(num);
    }
    inputFile.close();

    return v;
}