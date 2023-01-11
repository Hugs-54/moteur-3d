#ifndef __VERTEX_H__
#define __VERTEX_H__

class Vertex
{
private:
    float m_x;
    float m_y;
    float m_z;

public:
    Vertex(float x, float y, float z);
    float getX();
    float getY();
    float getZ();
};
#endif //__VERTEX_H__