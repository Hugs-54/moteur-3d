#ifndef __BOUNDINGBOX_H__
#define __BOUNDINGBOX_H__

#include <vector>
#include "vertex.h"
using namespace std;

class BoundingBox
{
private:
    vector<Vertex> corners;

public:
    BoundingBox(float xmin, float ymin, float xmax, float ymax);
    Vertex getPoint(int index);
};



#endif //__BOUNDINGBOX_H__