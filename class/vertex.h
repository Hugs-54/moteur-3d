#ifndef __VERTEX_H__
#define __VERTEX_H__

#include "tgaimage.h"

class Vertex
{
private:
    double f_x;
    double f_y;
    double f_z;
    int p_x;
    int p_y;
    int p_z;

public:
    Vertex(double x, double y, double z);
    Vertex();
    void resize(int width, int heigth);
    Vertex cross(const Vertex &v1, const Vertex &v2); 
    double getX();
    double getY();
    double getZ();
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    int getPixelX();
    int getPixelY();
    int getPixelZ();
    void setPixel(int x, int y);
};
#endif //__VERTEX_H__