#include "boundingbox.h"

BoundingBox::BoundingBox(float xmin, float ymin, float xmax, float ymax, int width, int heigth)
{
    Vertex v1(xmin, ymin, 0);
    v1.resize(width, heigth);
    corners.push_back(v1);

    Vertex v2(xmax, ymin, 0);
    v2.resize(width, heigth);
    corners.push_back(v2);

    Vertex v3(xmax, ymax, 0);
    v3.resize(width, heigth);
    corners.push_back(v3);

    Vertex v4(xmin, ymax, 0);
    v4.resize(width, heigth);
    corners.push_back(v4);
}

Vertex BoundingBox::getPoint(int index)
{
    return corners.at(index);
}