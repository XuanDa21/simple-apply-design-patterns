#include "THREEDRectangle.h"
void THREEDRectangle::showInfo() {
    std::cout << "3D rectangle have height is " << this -> height << std::endl;
    std::cout << "3D rectangle have width is " << this -> width << std::endl;
    std::cout << "3D rectangle have length is " << this -> length << std::endl;
}

void THREEDRectangle::setInit(vector<int> values) {
    this -> height = values[0];
    this -> width = values[1];
    this -> length = values[2];
}

string THREEDRectangle::showNameToModify() {
    return "3Drectangle";
}