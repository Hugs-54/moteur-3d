#include "triangle.h"

Triangle::Triangle(Vertex p1, Vertex p2, Vertex p3)
{
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
}

Vertex& Triangle::getPoint(int index)
{
    return points.at(index);
}

void Triangle::setColorComponent(TGAColor color,double compo,int index)
{
    points.at(index).setColor(color);
    points.at(index).setComponent(compo);
}