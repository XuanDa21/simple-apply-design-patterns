#ifndef TWODCircle_h
#define TWODCircle_h
#include "Shape.h"
#include <iostream>
class TWODCircle:public Shape {
    private:
        int radius;
        
    public:   

        void showInfo() override;

        void setInit(vector<int>) override;

        string showNameToModify() override;
        
};
#endif