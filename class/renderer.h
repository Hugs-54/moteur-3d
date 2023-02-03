#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "tgaimage.h"
#include "vertex.h"
#include "triangle.h"
#include <random>
#include <vector>
using namespace std;

class Renderer
{
private:
    int width;
    int heigth;
    float areaOfTriangle(Vertex v1, Vertex v2, Vertex v3);

public:
    Renderer(int w, int h);
    void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color);
    void renderPoints(vector<Vertex> vertexs, TGAImage &image, TGAColor color);
    void renderTriangles(vector<Triangle> triangles, TGAImage &image, TGAColor color);
    vector<int> createBox(Triangle t);
    double getIntensity(Vertex v1, Vertex v2, Vertex v3);
    bool isPointInsideTriangle(Triangle &t, float px, float py, Vertex &bary);
    void fillTriangles(vector<Triangle> triangles, TGAImage &image, TGAImage &texture, float *zbuffer);
    //void lookat(Vertex eye, Vertex center, Vertex up);
};

#endif //__RENDERER_H__