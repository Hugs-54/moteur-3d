#include "vertex.h"

Vertex::Vertex(float x, float y, float z) : f_x{x}, f_y(y), f_z(z)
{
}

void Vertex::resize(int width, int heigth)
{
    int w = width / 2;
    int h = heigth / 2;
    p_x = f_x * w + w;
    p_y = f_y * h + h;
}

float Vertex::getX()
{
    return f_x;
}

float Vertex::getY()
{
    return f_y;
}

float Vertex::getZ()
{
    return f_z;
}

int Vertex::getPixelX()
{
    return p_x;
}

int Vertex::getPixelY()
{
    return p_y;
}

int Vertex::getPixelZ()
{
    return p_z;
}

void Vertex::setPixel(int x, int y)
{
    p_x = x;
    p_y = y;
}