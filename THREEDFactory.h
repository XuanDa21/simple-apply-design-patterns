#include "Shape.h"
#include "AbstractFactory.h"
#include "THREEDRectangle.h"
#include "THREEDCircle.h"
static THREEDRectangle* instance3dRec;
static THREEDCircle* instance3dCir;
class THREEDFactory: public AbstractFactory {
    public:
    
        Shape* getShape(ShapeType type);

        static THREEDRectangle*  getInstance3dRec();
        
        static THREEDCircle* getInstance3DCir();
};