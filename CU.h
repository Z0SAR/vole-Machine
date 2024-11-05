#ifndef CU_H
#define CU_H
#include"Memory.h"
#include"Register.h"
using namespace std ;

class CU {
protected:
    bool halted;
public:
    CU():halted(false) {};

     void load(int idxReg,int intmem, Register&cpuRegister,Memory&memory);

     void load2(int idx, string value, Register& cpuRegister);
     void store(int idxReg,int idxMem,Register&cpuRegister,Memory&memory);
    void move (int idXRegx1,int idxReg2,Register&cpuRegister);
    void jump(int idxreg, int idxMem, Register& cpuRegister,  int &programCounter);
    bool is_halted()const;
    void halt();
};
#endif