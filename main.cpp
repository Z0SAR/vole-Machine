#include <iostream>
#include "Menu.h"
using namespace std;
int main() {
   Menu m;
    while (true) {
        m.displayMenu();
        m.enterChoice();
    }

}
