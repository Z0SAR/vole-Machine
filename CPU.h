#ifndef CPU_H
#define CPU_H
#include <bits/stdc++.h>
#include "Register.h"
#include "ALU.h"
#include "CU.h"
using namespace std;

class CPU {
private:
    int programCounter = 10;
    string instructionRegister;
    ALU alu;
    CU cu;
public:
    void fetch(Memory& memory);
    vector<int> decode();
    void runNextStep(Memory& memory);
    void runNextStep2(Memory& memory);
    void runNextStep3(Memory& memory);
    void execute( Memory &memory, vector<int>decoded);
    static Register cpuRegister;
};
#endif