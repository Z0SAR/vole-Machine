#include "CU.h"
#include "CPU.h"
Register CPU::cpuRegister;
vector<int> CPU::decode() {
    vector<int> decodedValues;
    for (int i = 0; i < 4; ++i) {
        char ch = instructionRegister[i];
        if (isxdigit(ch)) {
            decodedValues.push_back(stoi(instructionRegister.substr(i, 1), nullptr, 16));
        }
    }
    return decodedValues;
}
void CPU::fetch(Memory& memory) {
    instructionRegister = memory.getCell(programCounter) + memory.getCell(programCounter + 1);
    programCounter += 2;
}void CPU::runNextStep(Memory& memory) {
    while (programCounter < 128) {
        fetch(memory);
        if(instructionRegister=="C000")break;
        vector<int> decoded = decode();
        execute( memory, decoded);
    }
    cout<<"\n=============Memory status=================\n";
    memory.displayMemory();
    cout <<"\n=============Register status=================\n";
    cpuRegister.displayRegister();
    memory.outPutExpected();
}
void CPU::runNextStep3(Memory& memory) {
    while (programCounter < 128) {
        fetch(memory);
        if(instructionRegister=="C000")break;
        vector<int> decoded = decode();
        execute( memory, decoded);
    }
}
void CPU::runNextStep2(Memory& memory) {
        fetch(memory);
        vector<int> decoded = decode();
        execute( memory, decoded);
    cout<<"\n=============Memory status=================\n";
    memory.displayMemory();
    cout <<"\n=============Register status=================\n";
    cpuRegister.displayRegister();
    memory.outPutExpected();

}
void CPU::execute( Memory &memory, vector<int> decoded) {
    int OP=decoded[0];
    if(OP==1) {
        cu.load(decoded[1],decoded[2]*16+decoded[3],cpuRegister,memory);
    }
    else if(OP==2) {
        string val=alu.DecTohex(decoded[2])+alu.DecTohex(decoded[3]);
        cu.load2(decoded[1], val ,cpuRegister);
    }
    else if(OP==3) {
        cu.store(decoded[1],decoded[2]*16+decoded[3],cpuRegister,memory);
    }
    else if(OP==4) {
        cu.move(decoded[2],decoded[3],cpuRegister);
    }
    else if(OP==5) {
        alu.add(decoded[2],decoded[3],decoded[1],cpuRegister);
    }
    else if(OP==6) {
        alu.addfloat(decoded[2],decoded[3],decoded[1],cpuRegister);
    }
    else if(OP==11) {
        cu.jump(decoded[1],decoded[2]*16+decoded[3],cpuRegister,programCounter);
    }
    else if (OP==12)
    {
        cu.halt();
    }
    memory.sheckMemory(memory,memory.index);
}