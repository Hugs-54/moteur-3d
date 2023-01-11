#ifndef __VERTEX_H__
#define __VERTEX_H__

class Vertex
{
private:
    float f_x;
    float f_y;
    float f_z;
    int p_x;
    int p_y;
    int p_z;

public:
    Vertex(float x, float y, float z);
    void resize(int width, int heigth);
    float getX();
    float getY();
    float getZ();
    int getPixelX();
    int getPixelY();
    int getPixelZ();
    void setPixel(int x, int y);
};
#endif //__VERTEX_H__