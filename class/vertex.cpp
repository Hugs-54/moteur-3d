#include "vertex.h"

Vertex::Vertex(float x, float y, float z) : m_x{x}, m_y(y), m_z(z)
{
}

float Vertex::getX()
{
    return m_x;
}

float Vertex::getY()
{
    return m_y;
}

float Vertex::getZ()
{
    return m_z;
}