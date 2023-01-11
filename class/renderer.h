#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "tgaimage.h"
#include "vertex.h"
#include "boundingbox.h"
#include "triangle.h"
#include <vector>
using namespace std;

class Renderer
{
private:
    vector<BoundingBox> boxes;
    void renderBox(BoundingBox b, int width, int heigth, TGAImage &image, TGAColor color);

public:
    Renderer();
    void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color);
    void renderPoints(vector<Vertex> vertexs, int width, int heigth, TGAImage &image, TGAColor color);
    void renderTriangles(vector<Triangle> triangles, int width, int heigth, TGAImage &image, TGAColor color);
    void createBoundingBox(Triangle f);
    void renderBoxes(vector<Triangle> triangles, int width, int heigth, TGAImage &image, TGAColor color);
};

#endif //__RENDERER_H__