#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include <vector>
#include "vertex.h"
using namespace std;

class Triangle
{
private:
    vector<Vertex> points;
    vector<Vertex> vertexTexture;

public:
    Triangle(Vertex v1, Vertex v2, Vertex v3, Vertex vt1, Vertex vt2, Vertex vt3);
    Vertex &getPoint(int index);
    Vertex &getVertexTexture(int index);
};
#endif //__TRIANGLE_H__