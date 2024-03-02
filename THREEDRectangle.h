#ifndef THREEDRectangle_h
#define THREEDRectangle_h
#include "Shape.h"
#include <iostream>
class THREEDRectangle:public Shape {
    private:
        int height, width, length;
        
    public:   

        void showInfo() override;

        void setInit(vector<int>) override;

        string showNameToModify() override;
};
#endif