#ifndef TWODRectangle_h
#define TWODRectangle_h
#include <iostream>
#include <vector>
#include "Shape.h"
//#include "System.h"
class TWODRectangle:public Shape {
    private: 
        int height, width;

    public:  

        void showInfo() override;

        void setInit(vector<int>) override;

        string showNameToModify() override;
};
#endif