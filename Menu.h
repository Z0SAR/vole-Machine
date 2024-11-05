#ifndef _MENU_H
#define _MENU_H
#include "Machine.h"
#include <bits/stdtr1c++.h>
using namespace std;
class Menu
{
    Machine machine;
public:
     void displayMenu();
    void enterChoice();
};

#endif