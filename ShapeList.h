#ifndef ShapeList_h
#define ShapeList_h
#include "Shape.h"
#include <vector>
#include <iostream>
using namespace std;
class ShapeList {
    private: 
        vector<Shape*> shapes;

    public:  

        ShapeList();

        void addShapeList(Shape*);

        Shape* getShape(Shape*);

        vector<Shape*> getShapeList();

        void setShape(vector<Shape*>);

        //vector<Shape*> getShape();

};
#endif