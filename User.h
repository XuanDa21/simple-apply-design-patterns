#ifndef User_h
#define User_h
#include <iostream>
#include "System.h"
#include <fstream>
#include <cstring>
using namespace std;
class User {
    private:
        System system;
        vector<int> values;
        int result;
    public:    

        User();

        void addShape();

        void showListShape();

        void deleteShape();

        void undo();

        void redo();

        void modify();

        void getShape();

        void getSizeRec();

        void getSizeCir();


};
#endif