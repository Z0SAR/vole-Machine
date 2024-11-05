#include "Memory.h"
Memory::Memory()
{
    for (int i = 0 ; i < size ; i++) {memory[i] = "00";}
}

string Memory::getCell(int address)
{
    return memory[address] + memory[address + 1];
}
void Memory::setCell(int address, string val)
{
    if (val.length() == 4)
    {
        memory[address] = val.substr(0, 2);
        memory[address + 1] = val.substr(2, 2);
    }
}
void Memory::sheckMemory(Memory &memory, vector<string> &index) {
    string data = memory.getCell(0);
    if (index.empty() || data != index.back()) {
        index.push_back(data);
    }
    else {
        return;
    }
}



void Memory::outPutExpected() {
    cout << "\n===========Expected output==============\n";
    if (!index.empty()) {
        string previous = "";
        for (auto& i : index) {
            if (i != previous) {
                char c = static_cast<char>(stoi(i, nullptr, 16));
                cout << c << " ";
                previous = i;
            }
        }
    }
    cout << endl;
}

void Memory::displayMemory() {
    // int count = 0;
    // for (int i = 0 ; i < size ; i++)
    //{
    //     string index = index_sequence.DecTohex(i);
    //     cout << "M["<< index << "]: " <<  memory[i];
    //     if (count < 3){
    //         count++;
    //
    //         if  (i <= 15) {cout << "     ||               ";}
    //         else { cout << "    ||               ";}
    //
    //     }
    //     else
    //     {
    //         cout << endl;
    //         count = 0;
    //     }
    // }cout <<endl;
    //   }
    for (int row = 0; row < 16; row++)
    {
        for (int col = 0; col < 16; col++)
        {
            int index = row * 16 + col;
            string hexIndex = index_sequence.DecTohex(index);

            cout << "M[" << hexIndex << "]: " << memory[index];
            if (col < 15)
            {
                if(index < 16) {cout << "   |  ";}
                else {cout << "  |  "; }
            }

        }
        cout << endl;
    }
}
void Memory::setCell2(int address, string val) {
    memory[address] = val;
}