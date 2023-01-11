#ifndef __BOXANDTRIANGLE_H__
#define __BOXANDTRIANGLE_H__

#include "triangle.h"
#include "boundingbox.h"

class BoxAndTriangle
{
private:
    Triangle triangle;
    BoundingBox box;

public:
    BoxAndTriangle(Triangle t, BoundingBox bb);
    BoundingBox getBox();
    Triangle getTriangle();
};

#endif //__BOXANDTRIANGLE_H__