#include "FactoryMaker.h"

TWODFactory* FactoryMaker::getInstance2D() {
  if (nullptr ==  instanceTWOFactory) {
    instanceTWOFactory = new TWODFactory();
  }
  return instanceTWOFactory;
}

THREEDFactory* FactoryMaker::getInstance3D() {
  if (nullptr == instanceTHREEDFactory) {
    instanceTHREEDFactory = new THREEDFactory();
  }
  return instanceTHREEDFactory;
}

AbstractFactory* FactoryMaker::getFactory(FactoryType type) {
  AbstractFactory* factory = nullptr;
  switch(type)
  {
    case TWOD:  
        factory = getInstance2D();
        break;
    case THREED:
        factory = getInstance3D();
        break;
  }
  return factory;
}