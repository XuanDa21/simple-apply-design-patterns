#include "SingletonFactory.h"

SingletonFactory::SingletonFactory() {}

FactoryMaker* SingletonFactory::getInstance() {
    static FactoryMaker* factoryInstance;
    return factoryInstance;
}