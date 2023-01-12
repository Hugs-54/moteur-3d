#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include <vector>
#include "vertex.h"
using namespace std;

class Triangle
{
private:
    vector<Vertex> points;

public:
    Triangle(Vertex p1, Vertex p2, Vertex p3);
    Vertex& getPoint(int index);
    void setColorComponent(TGAColor color,double compo,int index);
};
#endif //__TRIANGLE_H__