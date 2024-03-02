#include "THREEDFactory.h"
THREEDRectangle* THREEDFactory::getInstance3dRec() {
  if (nullptr ==  instance3dRec) {
    instance3dRec = new THREEDRectangle();
  }
  return instance3dRec;
}

THREEDCircle* THREEDFactory::getInstance3DCir() {
  if (nullptr ==  instance3dCir) {
    instance3dCir = new THREEDCircle();
  }
  return instance3dCir;
}

Shape* THREEDFactory::getShape(ShapeType type) {
  Shape* shape = nullptr;
  switch (type) {
    case Rectangle:
        shape = getInstance3dRec();
        break;
    
    case Circle:
        shape = getInstance3DCir();
        break;
  }
  return shape;
}