#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include <vector>
#include "vertex.h"
#include "matrix.h"
using namespace std;

class Triangle
{
private:
    int width;
    int heigth;
    Vertex normal;
    vector<Vertex> points;
    vector<Vertex> vertexTexture;
    Matrix identityMatrix;
    Matrix projectionMatrix;
    Matrix modelview;

public:
    Triangle(int w, int h, Vertex v1, Vertex v2, Vertex v3, Vertex vt1, Vertex vt2, Vertex vt3);
    void generateModelView();
    Vertex getNormal();
    void movingCamera();
    Vertex &getPoint(int index);
    Vertex &getVertexTexture(int index);
};

#endif //__TRIANGLE_H__