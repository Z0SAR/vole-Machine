#include "Menu.h"
void Menu::displayMenu()
{
    cout << "========  Menu program  ========" << endl;
    cout << "1. Load Program from File" << endl;
    cout << "2. Run Program" << endl;
    cout << "3. Display State" << endl;
    cout << "4. Exit" << endl;
}
void Menu::enterChoice()
{
    string choice;
    cout << "Enter your choice please: ";
    cin >> choice;
    if (choice == "1")
    {
        string filename;
        cout << "Enter filename: ";
        cin.ignore();
        getline(cin,filename);
        machine.loadProgramFile(filename);
    }
    else if (choice == "2")
    {
        machine.executeProgram();
    }
    else if (choice == "3")
    {
        machine.outputState();
    }
    else if (choice == "4")
    {
       cout << "The program is exit" << endl;
       exit(0);
    }
    else 
    {
        cout << "Invalid choice try again" << endl;
    }
}