#include "tuple.h"

Tuple::Tuple(Vertex i1, int i2, int i3) : m_i1{i1}, m_i2{i2}, m_i3{i3}
{
}

Vertex Tuple::getI1()
{
    return m_i1;
}

int Tuple::getI2()
{
    return m_i2;
}

int Tuple::getI3()
{
    return m_i3;
}