#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "tgaimage.h"
#include "vertex.h"
#include "boundingbox.h"
#include "triangle.h"
#include "boxandtriangle.h"
#include <random>
#include <vector>
using namespace std;

class Renderer
{
private:
    int width;
    int heigth;
    vector<BoundingBox> boxes;
    vector<BoxAndTriangle> boxAndTriangle;
    void renderBox(BoundingBox b, TGAImage &image, TGAColor color);
    float areaOfTriangle(Vertex v1, Vertex v2, Vertex v3);
    void createBoxes(vector<Triangle> triangles);
    TGAColor randomize_color();

public:
    Renderer(int w, int h);
    void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color);
    void renderPoints(vector<Vertex> vertexs, TGAImage &image, TGAColor color);
    void renderTriangles(vector<Triangle> triangles, TGAImage &image, TGAColor color);
    void createBoundingBox(Triangle t);
    vector<int> createBox(Triangle t);
    double getIntensity(Vertex v1, Vertex v2, Vertex v3);
    void renderBoxes(vector<Triangle> triangles, TGAImage &image, TGAColor color);
    bool isPointInsideTriangle(Triangle& t, float px, float py, Vertex& bary);
    void fillTriangles(vector<Triangle> triangles, TGAImage &image, float *zbuffer);
};

#endif //__RENDERER_H__