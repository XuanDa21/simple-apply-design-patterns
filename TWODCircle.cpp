#include "TWODCircle.h"
void TWODCircle::showInfo() {
    std::cout << "2D circle has radius is " << this -> radius << std::endl;
}


void TWODCircle::setInit(vector<int> values) {
    this -> radius = values[0];
}

string TWODCircle::showNameToModify() {
    return "2Dcircle";
}
