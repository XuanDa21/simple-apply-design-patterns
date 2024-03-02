#ifndef THREEDCircle_h
#define THREEDCircle_h
#include "Shape.h"
#include <iostream>
class THREEDCircle:public Shape {
    private:
        int radius;

    public:   

        void showInfo() override;

        void setInit(vector<int>) override;

        string showNameToModify() override;

};
#endif