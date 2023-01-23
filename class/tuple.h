#ifndef __TUPLE_H__
#define __TUPLE_H__

#include "vertex.h"

class Tuple
{
private:
    Vertex m_i1;
    Vertex m_i2;
    int m_i3;

public:
    Tuple(Vertex i1, Vertex i2, int i3);
    Vertex getI1();
    Vertex getI2();
    int getI3();
};
#endif //__TUPLE_H__