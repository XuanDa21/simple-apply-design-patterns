#include "Shape.h"
#include "AbstractFactory.h"
#include "TWODRectangle.h"
#include "TWODCircle.h"
static TWODRectangle* instance2dRec;
static TWODCircle* instance2dCir;

class TWODFactory: public AbstractFactory {
    public:
        Shape* getShape(ShapeType type);

        static TWODRectangle*  getInstance2dRec();
        
        static TWODCircle* getInstance2dCir();

};