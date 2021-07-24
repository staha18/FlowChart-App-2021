#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class CorrChecker
{
public:
    int check();
private:
    char myFilePath[100];   //путь к .cpp файлу без названия самого файла
    char myFileName[50];    //название .cpp файла
    string myBatPath;       //путь к .bat файлу вместе с его названием
    ofstream batch;
    
};

