#include "TWODRectangle.h"
void TWODRectangle::showInfo(){
    std::cout << "2D rectangle has heigth is " << this -> height << std::endl;
    std::cout << "2D rectangle has width is " << this -> width << std::endl;
}

void TWODRectangle::setInit(vector<int> values) {
    this -> height = values[0];
    this -> width = values[1];
}

string TWODRectangle::showNameToModify() {
   return "2Drectangle";
}