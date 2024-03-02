#ifndef Shape_h
#define Shape_h
#include <vector> 
#include <string>
using namespace std;
enum ShapeType {
    Rectangle,
    Circle
};
class Shape {
    private:
    
    public:    
        //virtual void draw() = 0;

        virtual void showInfo() = 0;

        virtual void setInit(vector<int>) = 0;

        virtual string showNameToModify() = 0;

};
#endif