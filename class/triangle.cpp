#include "triangle.h"

Triangle::Triangle(Vertex v1, Vertex v2, Vertex v3, Vertex vt1, Vertex vt2, Vertex vt3)
{
    points.push_back(v1);
    points.push_back(v2);
    points.push_back(v3);
    vertexTexture.push_back(vt1);
    vertexTexture.push_back(vt2);
    vertexTexture.push_back(vt3);
}

Vertex &Triangle::getPoint(int index)
{
    return points.at(index);
}

Vertex &Triangle::getVertexTexture(int index)
{
    return vertexTexture.at(index);
}