#include "User.h"

User::User() {}

void User::addShape() {
    char choice;
    result = 0;
    cout << "2 - to choose 2D" << endl;
    cout << "3 - to choose 3D" << endl;
    cout << "-> ";
    cin >> choice;
    switch(choice) {
        case '2':
            system.setFactory(TWOD);
            getShape();
            system.getShapes();
            system.getIds();
            break;
        case '3':
            system.setFactory(THREED);
            result = 3;
            getShape();
            system.getShapes();
            system.getIds();
            break;
    }
}


void User::showListShape() {
    int i = 0;
    for(auto val:system.getShapes()) {
        val -> showInfo();
        cout << "id is " << system.getIds()[i] << endl;
        cout << "---------------------------" << endl;
        i++;
    }
}

void User::deleteShape() {
    int id;
    cout << "Enter shape id you wanna delete: ";
    cin >> id;
    system.deleteShape(id);
}

void User::undo() {
    system.undo();
}

void User::modify() {
    int id, result;
    cout << "Enter shape id you wanna modify: ";
    cin >> id;
    int h, w, a, r;
    switch(system.checkShape(id)) {
        case 1:
            cout << "Enter value of radius: ";
            cin >> r;
            values.push_back(r);
            break;
        case 2:
            cout << "Enter value of radius: ";
            cin >> r;
            values.push_back(r);
            break;
        case 3:
            cout << "Enter value of height: ";
            cin >> h;
            cout << "Enter value of width: ";
            cin >> w;
            values.push_back(h);
            values.push_back(w);
            break;
        case 4:
            cout << "Enter value of height: ";
            cin >> h;
            cout << "Enter value of width: ";
            cin >> w;
            cout << "Enter value of length: ";
            cin >> a;
            values.push_back(h);
            values.push_back(w);
            values.push_back(a);
            break;
        default: 
            cout << "have no shape!" << endl;
            break;
    }
    system.modify(values, id);
}
    

void User::redo() {
    system.redo();
}

void User::getShape() {
    char choice;
    cout << "r - to choose rectangle" << endl;
    cout << "c - to choose circle" << endl;
    cout << "-> ";
    cin >> choice;
    switch(choice) {
        case 'r':
            system.setRectangleShape();
            getSizeRec();
            break;
        case 'c':
            system.setCircleShape();
            getSizeCir();
            break;
    }
}

void User::getSizeRec() {
    int a, h, w;
    if(result == 3) {
        cout << "Enter value of height: ";
        cin >> h;
        cout << "Enter value of width: ";
        cin >> w;
        cout << "Enter value of length: ";
        cin >> a;
        values.push_back(h);
        values.push_back(w);
        values.push_back(a);
    }
    else {
        cout << "Enter value of height: ";
        cin >> h;
        cout << "Enter value of width: ";
        cin >> w;
        values.push_back(h);
        values.push_back(w);
    }
    system.setInit(values);
}

void User::getSizeCir() {
    int r;
    cout << "Enter value of radius: ";
    cin >> r;
    values.push_back(r);
    system.setInit(values);
}
