# include "Register.h"
Register::Register()
{
    for (int i = 0 ; i < size ; i++) {memory[i] = "00";}
}
string Register::getCell(int address)
{
    return memory[address];
}
void  Register::setCell(int address, string val)
{
    memory[address] = val;
}
    void Register::displayRegister()
    {
        int count = 0;
        for (int i = 0 ; i < size ; i++)
        {
            cout << "R["<< i << "]: " <<  memory[i];
            if (count < 2){
                count++;
                if (i >=  10) {cout << "  ||               ";}
                else { cout << "   ||               ";}

            }
            else
            {
                cout << endl;
                count = 0;
            }
        }cout<<endl;
}

