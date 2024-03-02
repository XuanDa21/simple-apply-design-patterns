#include <iostream> 
#include "User.h"
void menuStart();

int main() {
    menuStart();
    return 0;
}

void menuStart() {
    char choice;
    while(true) {
        cout << "choose a option in the menu" << endl;
        cout << "a - add new shape" << endl;
        cout << "d - delete shape" << endl;
        cout << "s - show shape list" << endl;
        cout << "u - undo" << endl;
        cout << "r - redo" << endl;
        cout << "m - modify" << endl;
        cout << "e - exit application" << endl;
        cout << "-> ";
        cin >> choice;
        User user;
        switch(choice) {
            case 'a':
                user.addShape();
                break;
            case 'd':
                user.deleteShape();
                break;
            case 's':
                user.showListShape();
                break;
            case 'u':
                user.undo();
                break;
            case 'r':
                user.redo();
                break;
            case 'm':
                user.modify();
                break;
            case 'e':
                exit(0);
            default: 
                cout << "invalid option!!!" << endl;
                break;
        }
    }
}