#include "System.h"
FactoryMaker* System::getInstance() {
    if (nullptr ==  instanceFactoryMaker) {
        instanceFactoryMaker = new FactoryMaker();
    }
    return instanceFactoryMaker;
}

void System::setFactory(FactoryType type) {
    factory = getInstance() -> getFactory(type);
}

void System::setRectangleShape() {
    shape = factory -> getShape(ShapeType::Rectangle);
}

void System::setCircleShape() {
    shape = factory -> getShape(ShapeType::Circle);
}

void System::setInit(vector<int> values) {
    flag = 1;
    srand((unsigned) time(NULL));
    int random = rand() % 10;
    shapes.push_back(shape);
    idShapes.push_back(random);
    temValues.push_back(values);
    shape -> setInit(values);
}

vector<Shape*> System::getShapes() {
    return shapes;
}

vector<int> System::getIds() {
    return idShapes;
}

void System::deleteShape(int id) {
    flag = 2;
    for(int i = 0; i < idShapes.size(); ++i) {
        if(id == idShapes[i]) {
            shapesModi.push_back(shapes[i]);
            idsModi.push_back(idShapes[i]);
            positions.push_back(i);
            shapes.erase(shapes.begin() + i);
            idShapes.erase(idShapes.begin() +i);
        }
    }
}

void System::undo() {
    if(flag == 2) {
        tempShapes = shapesModi;
        tempIds = idsModi;
        Shape* tempShape = tempShapes.back();
        int tempId = tempIds.back();
        tempShapes.pop_back();
        tempIds.pop_back();
        shapes.emplace(shapes.begin()+positions.back(), tempShape);
        idShapes.emplace(idShapes.begin()+positions.back(), tempId);
    }
    
    else if(flag == 3) {
        tempShapes = shapesModi;
        tempIds = idsModi;
        Shape* tempShape = shapesModi.back();
        int tempId = idsModi.back();
        tempShapes.pop_back();
        tempIds.pop_back();
        shapes.erase(shapes.begin()+positions.back());
        idShapes.erase(idShapes.begin()+positions.back());
        shapes.emplace(shapes.begin()+positions.back(), tempShape);
        idShapes.emplace(idShapes.begin()+positions.back(), tempId);
    }

    else {
        Shape* tempshape = shapes.back();
        int tempId  = idShapes.back();
        shapes.pop_back();
        idShapes.pop_back();
        tempShapes.push_back(tempshape);
        tempIds.push_back(tempId);
    }   
}

void System::redo() {
    if(flag == 2) {
        Shape* tempshape = shapes.back();
        int tempId  = idShapes.back();
        shapes.erase(shapes.begin()+positions.back());
        idShapes.erase(idShapes.begin()+positions.back());
        tempShapes.push_back(tempshape);
        tempIds.push_back(tempId);
    }

    else if(flag == 3) {
        setShapeModify();
        Shape* tempshape = tempModi.back();
        int tempId = idsModi.back();
        shapes.erase(shapes.begin()+positions.back());
        idShapes.erase(idShapes.begin()+positions.back());
        shapes.emplace(shapes.begin()+positions.back(), tempshape);
        idShapes.emplace(idShapes.begin()+positions.back(), tempId);
        tempShapes.push_back(tempshape);
        tempIds.push_back(tempId);
    }

    else {
        Shape* tempShape = tempShapes.back();
        int tempId = tempIds.back();
        tempShapes.pop_back();
        tempIds.pop_back();
        shapes.push_back(tempShape);
        idShapes.push_back(tempId);
    }
}

int System::checkShape(int id) {
    int checkShape = 0;
    Shape* tempshape;
    for(int i = 0; i < idShapes.size(); ++i) {
        if(id == idShapes[i]) {
            a = shapes[i] -> showNameToModify().compare("2Dcircle");
            b = shapes[i] -> showNameToModify().compare("3Dcircle");
            c = shapes[i] -> showNameToModify().compare("2Drectangle");
            d = shapes[i] -> showNameToModify().compare("3Drectangle");
            if(a == 0) {
                checkShape = 1;
                setFactory(TWOD);
                tempshape = factory -> getShape(ShapeType::Circle);
                tempshape -> setInit(temValues[i]);
                idsModi.push_back(idShapes[i]);
            }
            else if(b == 0) {
                setFactory(THREED);
                tempshape = factory -> getShape(ShapeType::Circle);
                tempshape -> setInit(temValues[i]);
                idsModi.push_back(idShapes[i]);
                checkShape = 2;
            }
            else if(c == 0) {
                setFactory(TWOD);
                tempshape = factory -> getShape(ShapeType::Rectangle);
                tempshape -> setInit(temValues[i]);
                idsModi.push_back(idShapes[i]);
                checkShape = 3;
            }
            else if(d == 0) {
                setFactory(THREED);
                tempshape = factory -> getShape(ShapeType::Rectangle);
                tempshape -> setInit(temValues[i]);
                idsModi.push_back(idShapes[i]);
                checkShape = 4;
            }
            shapesModi.push_back(tempshape);
        }
    }
    return checkShape;
}

void System::setShapeModify() {
    Shape* tempShapeModi;
    if(a == 0) {
        setFactory(TWOD);
        tempShapeModi = factory -> getShape(ShapeType::Circle);
        tempShapeModi -> setInit(temValue);
    }   
    else if(b == 0) {
        setFactory(THREED);
        tempShapeModi = factory -> getShape(ShapeType::Circle);
        tempShapeModi -> setInit(temValue);
    }
    else if(c == 0) {
        setFactory(TWOD);
        tempShapeModi = factory -> getShape(ShapeType::Rectangle);
        tempShapeModi -> setInit(temValue);
    }
    else if(d == 0){
        setFactory(THREED);
        tempShapeModi = factory -> getShape(ShapeType::Rectangle);
        tempShapeModi -> setInit(temValue);
    }
    tempModi.push_back(tempShapeModi);
}

void System::modify(vector<int> values, int id) {
    flag = 3;
    for(int i = 0; i < idShapes.size(); ++i) {
        if(id == idShapes[i]) {
            positions.push_back(i);
            Shape* tempShape = shapes[i];
            int tempId = idShapes[i];
            shapes[i] -> setInit(values);
            shapes.erase(shapes.begin()+i);
            idShapes.erase(idShapes.begin()+i);
            shapes.insert(shapes.begin()+i, tempShape);
            idShapes.insert(idShapes.begin()+i, tempId);
        }
    }
    temValue = values;
}