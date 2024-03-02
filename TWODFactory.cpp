#include "TWODFactory.h"

TWODRectangle* TWODFactory::getInstance2dRec() {
  if (nullptr ==  instance2dRec) {
    instance2dRec = new TWODRectangle();
  }
  return instance2dRec;
}

TWODCircle* TWODFactory::getInstance2dCir() {
  if (nullptr ==  instance2dCir) {
    instance2dCir = new TWODCircle();
  }
  return instance2dCir;
}

Shape* TWODFactory::getShape(ShapeType type) {
  Shape* shape = nullptr;
  switch (type)
  {
    case Rectangle:
        shape = getInstance2dRec();
        break;
    
    case Circle:
        shape = getInstance2dCir();
        break;
  }
  return shape;
}