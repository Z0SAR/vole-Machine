#ifndef _MEMORY_H
#define _MEMORY_H
#include <bits/stdtr1c++.h>
#include"ALU.h"
using namespace std;
class Memory
{
private:
    string memory[256];
    int size = 256;


public:
    void outPutExpected();
    vector<string>index;
    void sheckMemory(Memory& memory ,vector<string>&index);
    ALU index_sequence;
    Memory();
    string getCell(int address);
    void setCell2(int address, string val);
    void setCell(int address, string val);
    void displayMemory();
};
#endif