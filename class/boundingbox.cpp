#include "boundingbox.h"

BoundingBox::BoundingBox(float xmin, float ymin, float xmax, float ymax){
    corners.push_back(Vertex(xmin,ymin,0));
    corners.push_back(Vertex(xmax,ymin,0));
    corners.push_back(Vertex(xmax,ymax,0));
    corners.push_back(Vertex(xmin,ymax,0));
}

Vertex BoundingBox::getPoint(int index){
    return corners.at(index);
}