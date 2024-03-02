#include "ShapeList.h"
ShapeList::ShapeList() {}
void ShapeList::setShape(vector<Shape*> shapes) {
    this -> shapes = shapes;
}

void ShapeList::addShapeList(Shape* shape) {
    //shape -> showInfo();
    shapes.push_back(shape);
}

Shape* ShapeList::getShape(Shape* shape) {
    return shape;
}


vector<Shape*> ShapeList::getShapeList() {
    return shapes;
}
