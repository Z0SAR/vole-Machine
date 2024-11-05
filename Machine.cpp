#include "Machine.h"
bool isFileEmpty(const std::string& filename) {
    std::ifstream file(filename);
    return file.peek() == std::ifstream::traits_type::eof();
}
void Machine::loadProgramFile(const string& filename) {
    if (isFileEmpty(filename))
    {
        cerr << "Error: File is Empty . Please enter a valid .txt file." << endl;
        return;
    }
    if (filename.size() < 4 || filename.substr(filename.size() - 4) != ".txt")
    {
        cerr << "Error: Invalid file format. Please enter a .txt file." << endl;
        return;
    }
    ifstream file(filename);
    if (!file)
    {
        cerr << "Error: Cannot open file " << filename << endl;
        return;
    }
    string instruction;
    address = 10;
    cout <<"Do you want to Execute the Program and Print cell line BY line or After Ending :\n1)line By line \n2)After Ending \n";
    string s;cin >>s;
    while (s!="1"&&s!="2") {
        cout<<"Invalid choice enter 1 or to \n";
        cin >>s;
    }
    if(s=="2")
    {
        while (file >> instruction)
        {
            memory.setCell(address, instruction);
            address += 2;
        }
        file.close();
        processor.runNextStep(memory);
    }
    else if(s=="1") {
        while (file >> instruction)
        {
            memory.setCell(address, instruction);
            address += 2;
            processor.runNextStep2(memory);
        }
        file.close();
    }
}
void Machine::outputState()
{
    cout << "=========== Machine state ============" << endl;
    cout << "=========== Memory contents ==========" << endl;
    memory.displayMemory();
    cout << "=========== Register contents  ==========" << endl;
    CPU::cpuRegister.displayRegister();
    memory.outPutExpected();
}
void Machine::executeProgram()
{
    processor.runNextStep3(memory);
}