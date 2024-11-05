#ifndef _MACHINE_H
#define _MACHINE_H
#include "CPU.h"
#include"Memory.h"
#include "ALU.h"
#include <bits/stdtr1c++.h>
# include "Register.h"
using namespace std;
class Machine
{
protected:
    CPU processor;
    Memory memory;
    ALU a;
    int address;

public:
    void loadProgramFile(const string& filename);
    void outputState();
    void executeProgram();

};
#endif