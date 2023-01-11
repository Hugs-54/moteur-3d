#ifndef __TUPLE_H__
#define __TUPLE_H__

#include "vertex.h"

class Tuple
{
private:
    Vertex m_i1;
    int m_i2;
    int m_i3;

public:
    Tuple(Vertex i1, int i2, int i3);
    Vertex getI1();
    int getI2();
    int getI3();
};
#endif //__TUPLE_H__