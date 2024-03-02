#ifndef SingletonFactory_h
#define SingletonFactory_h
#include "FactoryMaker.h"
class SingletonFactory {
    private:
        SingletonFactory();
    public:    
        static FactoryMaker* getInstance();
};
#endif