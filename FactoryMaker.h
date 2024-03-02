#ifndef FactoryMaker_h
#define FactoryMaker_h
#include "Shape.h"
#include "AbstractFactory.h"
#include "TWODFactory.h"
#include "THREEDFactory.h"
static TWODFactory* instanceTWOFactory;
static THREEDFactory* instanceTHREEDFactory;
enum FactoryType {
    TWOD,
    THREED
};
class FactoryMaker {
    public:
        AbstractFactory* getFactory(FactoryType type);

        static TWODFactory*  getInstance2D();
        
        static THREEDFactory* getInstance3D();
};
#endif