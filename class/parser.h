#ifndef __PARSER_H__
#define __PARSER_H__

#include <iostream>
#include <sstream>
#include <fstream>
#include "vertex.h"
#include "tuple.h"
#include "triangle.h"
#include "matrix.h"
#include <vector>
using namespace std;

class Parser
{
public:
    Parser();
    vector<Vertex> points;
    vector<Triangle> triangles;
    vector<Vertex> pointsTextures;
    vector<Vertex> vn;
    void parse(string fileName, int width, int heigth, double dstZ);
    Tuple parseTuple(string t);
    vector<Vertex> getPoints();
    vector<Triangle> getTriangles();
    Vertex project(Vertex &v, double distance_z);
};

#endif //__PARSER_H__
