#include "triangle.h"
#include <iostream>

Vertex eyeCenter(1., 1., 3.);
Vertex center(0., 0., 0.);
Vertex axe(0., 1., 0.);
Vertex diff_pov_center(eyeCenter.getX()-center.getX(),eyeCenter.getY()-center.getY(),eyeCenter.getZ()-center.getZ());


Triangle::Triangle(int w, int h, Vertex v1, Vertex v2, Vertex v3, Vertex vt1, Vertex vt2, Vertex vt3)
{
    identityMatrix = Matrix::identify(4);
    int x = w/8;
    int y = h/8;
    identityMatrix[0][3] = x+(w*.75f)/2.f;
    identityMatrix[1][3] = y+(h*.75f)/2.f;
    identityMatrix[2][3] = 255/2.f;

    identityMatrix[0][0] = (w*.75f)/2.f;
    identityMatrix[1][1] = (h*.75f)/2.f;
    identityMatrix[2][2] = 255/2.f;
    
    projectionMatrix = Matrix::identify(4);
    projectionMatrix[3][2] = -1.f/diff_pov_center.norm();
    modelview = Matrix::identify(4);
    generateModelView();
    
    Matrix m1(v1);
    Matrix m2(v2);
    Matrix m3(v3);
    Matrix z1 = identityMatrix*projectionMatrix*modelview*m1;
    Matrix z2 = identityMatrix*projectionMatrix*modelview*m2;
    Matrix z3 = identityMatrix*projectionMatrix*modelview*m3;
    
    Vertex ve1 = z1.matrixToVertex();
    Vertex ve2 = z2.matrixToVertex();
    Vertex ve3 = z3.matrixToVertex();

    
    points.push_back(v1);
    points.push_back(v2);
    points.push_back(v3);
    vertexTexture.push_back(vt1);
    vertexTexture.push_back(vt2);
    vertexTexture.push_back(vt3);
}

void Triangle::generateModelView(){
    Vertex x, y, z;

    z = diff_pov_center.normalize();
    x = x.cross(axe, z);

    x = x.normalize();
    y = y.cross(z, x);
    y = y.normalize();
    
    modelview[0][0] = x.getX();
    modelview[0][1] = x.getY();
    modelview[0][2] = x.getZ();
    modelview[0][3] = -center.getX();

    modelview[1][0] = y.getX();
    modelview[1][1] = y.getY();
    modelview[1][2] = y.getZ();
    modelview[1][3] = -center.getY();

    modelview[2][0] = z.getX();
    modelview[2][1] = z.getY();
    modelview[2][2] = z.getZ();
    modelview[2][3] = -center.getZ();
}

Vertex &Triangle::getPoint(int index)
{
    return points.at(index);
}

Vertex &Triangle::getVertexTexture(int index)
{
    return vertexTexture.at(index);
}