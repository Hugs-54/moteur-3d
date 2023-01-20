#ifndef __PARSER_H__
#define __PARSER_H__

#include <iostream>
#include <sstream>
#include <fstream>
#include "vertex.h"
#include "tuple.h"
#include "triangle.h"
#include <vector>
using namespace std;

class Parser
{
public:
    Parser();
    vector<Vertex> points;
    vector<Triangle> triangles;
    vector<Vertex> pointsTextures;
    void parse(string fileName, int width, int heigth);
    Tuple parseTuple(string t);
    vector<Vertex> getPoints();
    vector<Triangle> getTriangles();
};

#endif //__PARSER_H__
