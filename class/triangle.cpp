#include "triangle.h"
#include <iostream>

Vertex eyeCenter(1., 1., 3.); // Rotation sur les 3 axes
Vertex center(0., 0., 0.);
Vertex axe(0., 1., 0.);
Vertex diff_pov_center(eyeCenter.getX() - center.getX(), eyeCenter.getY() - center.getY(), eyeCenter.getZ() - center.getZ());

Triangle::Triangle(int w, int h, Vertex v1, Vertex v2, Vertex v3, Vertex vt1, Vertex vt2, Vertex vt3) : width{w}, heigth{h}
{
    points.push_back(v1);
    points.push_back(v2);
    points.push_back(v3);

    Vertex vAB(v2.getX() - v1.getX(), v2.getY() - v1.getY(), v2.getZ() - v1.getZ());
    Vertex vAC(v3.getX() - v1.getX(), v3.getY() - v1.getY(), v3.getZ() - v1.getZ());
    double X = vAB.getY() * vAC.getZ() - vAB.getZ() * vAC.getY();
    double Y = vAB.getZ() * vAC.getX() - vAB.getX() * vAC.getZ();
    double Z = vAB.getX() * vAC.getY() - vAB.getY() * vAC.getX();
    normal = Vertex(X, Y, Z);

    vertexTexture.push_back(vt1);
    vertexTexture.push_back(vt2);
    vertexTexture.push_back(vt3);
}

void Triangle::movingCamera()
{
    // Position dans l'image
    identityMatrix = Matrix::identify(4);
    int width = 1000;
    int heigth = 1000;
    float x = width / 8.;
    float y = heigth / 8.;
    identityMatrix[0][3] = x + (width * .75f) / 2.f;
    identityMatrix[1][3] = y + (heigth * .75f) / 2.f;
    identityMatrix[2][3] = 255 / 2.f;

    identityMatrix[0][0] = (width * .75f) / 2.f;
    identityMatrix[1][1] = (heigth * .75f) / 2.f;
    identityMatrix[2][2] = 255 / 2.f;

    // L'angle camera
    projectionMatrix = Matrix::identify(4);
    projectionMatrix[3][2] = -1.f / diff_pov_center.norm();
    // Profondeur camera
    modelview = Matrix::identify(4);
    generateModelView();

    Matrix z1 = identityMatrix * projectionMatrix * modelview * Matrix(points.at(0));
    Matrix z2 = identityMatrix * projectionMatrix * modelview * Matrix(points.at(1));
    Matrix z3 = identityMatrix * projectionMatrix * modelview * Matrix(points.at(2));

    Vertex ve1 = z1.matrixToVertex();
    Vertex ve2 = z2.matrixToVertex();
    Vertex ve3 = z3.matrixToVertex();

    points.clear();
    points.push_back(ve1);
    points.push_back(ve2);
    points.push_back(ve3);
}

void Triangle::generateModelView()
{
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

Vertex Triangle::getNormal()
{
    return normal;
}
