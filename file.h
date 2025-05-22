// Created on 07-May-25
//

#ifndef MINI_PROJECT___1_FILE_H
#define MINI_PROJECT___1_FILE_H

#include "string"

//store an array to file,check for previous file if available

void fileExists(const std::string& fileName);

bool writeFile(int arr[], int size,const std::string& fileName);


#endif //MINI_PROJECT___1_FILE_H
