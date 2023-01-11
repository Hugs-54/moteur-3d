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
    // BoxAndFace(Face f, BoundingBox bb);
};

#endif //__BOXANDTRIANGLE_H__