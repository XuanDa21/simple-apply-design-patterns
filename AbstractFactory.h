#ifndef AbstractFactory_h
#define AbstractFactory_h
#include "Shape.h"
class AbstractFactory {
    public:    
        virtual Shape* getShape(ShapeType type) = 0;
};
#endif