#ifndef System_h
#define System_h
#include "FactoryMaker.h"
#include "Shape.h"
#include <iostream>
#include <cstring>
using namespace std;
static vector<Shape*> shapes;
static vector<int> idShapes;

static vector<Shape*> tempShapes;
static vector<int> tempIds;
static vector<vector<int>> temValues;

static vector<Shape*> shapesModi;
static vector<int> idsModi;
static vector<int> positions;

static FactoryMaker* instanceFactoryMaker;
class System {
    private: 
        AbstractFactory* factory;
        Shape* shape;
        vector<Shape*> tempModi;
        vector<int> temValue;
        int flag, a, b, c, d;

    public:  
        
        void setFactory(FactoryType);

        void setRectangleShape();

        void setCircleShape();

        vector<int> getIds();

        void deleteShape(int);

        void undo();

        void redo();

        int checkShape(int);

        void setInit(vector<int>);

        vector<Shape*> getShapes();

        void setShapeModify();

        void modify(vector<int>, int);

        static FactoryMaker* getInstance();
};
#endif