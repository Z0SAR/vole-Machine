#ifndef _REGISTER_H
#define _REGISTER_H
#include <bits/stdtr1c++.h>
using namespace std;
class Register 
{
private:
    string memory[16];
    int size = 16;
public:
    Register();
    string getCell (int address);
    void setCell (int address, string val );
    void displayRegister();
};
#endif