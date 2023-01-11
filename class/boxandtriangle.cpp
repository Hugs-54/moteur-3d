#include "boxandtriangle.h"

BoxAndTriangle::BoxAndTriangle(Triangle t, BoundingBox bb) : triangle{t}, box{bb} {}

BoundingBox BoxAndTriangle::getBox()
{
    return box;
}

Triangle BoxAndTriangle::getTriangle()
{
    return triangle;
}