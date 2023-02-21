#ifndef __VERTEX_H__
#define __VERTEX_H__

#include "tgaimage.h"
#include "math.h"

class Vertex
{
private:
    double f_x;
    double f_y;
    double f_z;

public:
    Vertex(double x, double y, double z);
    Vertex();
    Vertex cross(Vertex v1, Vertex v2);
    float norm() const { return std::sqrt(f_x * f_x + f_y * f_y + f_z * f_z); }
    Vertex normalize();
    double getX();
    double getY();
    double getZ();
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    double dot(Vertex v);
    Vertex dot(double d);
    Vertex sub(Vertex v);
};
#endif //__VERTEX_H__