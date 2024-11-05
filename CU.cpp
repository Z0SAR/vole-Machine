#include "CU.h"
void CU::load(int idxReg, int intmem, Register &cpuRegister, Memory &memory) {
    string data = memory.getCell(intmem);
    cpuRegister.setCell(idxReg, data);
}
void CU::load2(int idxReg,string val,Register& cpuRegister) {
    cpuRegister.setCell(idxReg,val);
}
void CU::store(int idxReg,int idxMem,Register&cpuRegister,Memory&memory) {
    string data =cpuRegister.getCell(idxReg);
    memory.setCell2(idxMem,data);
}
void CU::move(int idXRegx1,int idxReg2,Register&cpuRegister) {
    string data=cpuRegister.getCell(idXRegx1);
    cpuRegister.setCell(idxReg2,data);
}
void CU::jump(int idxreg, int idxMem, Register& cpuRegister,int &programCounter){

        string data=cpuRegister.getCell(idxreg);
        string data2=cpuRegister.getCell(0);
       if (data==data2){
            programCounter=idxMem;
    }
}
void CU::halt() {
    halted=true;
}
bool CU::is_halted() const {
    return halted;
}