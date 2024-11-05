#ifndef _ALU_H
#define _ALU_H
#include <bits/stdtr1c++.h>
# include "Register.h"
using namespace std;
class ALU
{
protected:
    string HexToBinary (const string& hex);
    int binaryToDecimal(const string& binary);
    string decimalToBinary(int decimal);
    string binaryToHex(const string& binary);
    string twosComplement( string& bin);
    string floatToBinary(float number);
    float binaryToFloat( string &binary);
    public :
        int hexToDec(const string& hex);
    string DecTohex(const int& Dec);
    void add(int idx1, int idx2, int idx3, Register&r);
    void addfloat(int idx1, int idx2, int idx3, Register& cpuRegister);

};
#endif