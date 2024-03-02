#include "THREEDCircle.h"
void THREEDCircle::showInfo() {
    std::cout << "3D circle has Radius is " << this -> radius << std::endl;
}

void THREEDCircle::setInit(vector<int> values) {
    this -> radius = values[0];
}

string THREEDCircle::showNameToModify() {
    return "3Dcircle";
}