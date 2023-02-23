#include "vertex.h"

Vertex::Vertex(double x, double y, double z) : f_x{x}, f_y(y), f_z(z)
{
}

Vertex::Vertex() : f_x{0}, f_y(0), f_z(0)
{
}

Vertex Vertex::cross(Vertex v1, Vertex v2)
{
    return Vertex(
        v1.getY() * v2.getZ() - v1.getZ() * v2.getY(),
        v1.getZ() * v2.getX() - v1.getX() * v2.getZ(),
        v1.getX() * v2.getY() - v1.getY() * v2.getX());
}

Vertex Vertex::normalize()
{
    return Vertex(
        f_x * (1. / norm()),
        f_y * (1. / norm()),
        f_z * (1. / norm()));
}

double Vertex::getX()
{
    return f_x;
}

double Vertex::getY()
{
    return f_y;
}

double Vertex::getZ()
{
    return f_z;
}

void Vertex::setX(double x)
{
    f_x = x;
}

void Vertex::setY(double y)
{
    f_y = y;
}

void Vertex::setZ(double z)
{
    f_z = z;
}