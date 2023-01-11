#include "renderer.h"
#include <iostream>
Renderer::Renderer() {}

void Renderer::line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color)
{
    bool steep = false;
    if (std::abs(x0 - x1) < std::abs(y0 - y1))
    { // if the line is steep, we transpose the image
        std::swap(x0, y0);
        std::swap(x1, y1);
        steep = true;
    }
    if (x0 > x1)
    { // make it left−to−right
        std::swap(x0, x1);
        std::swap(y0, y1);
    }
    for (int x = x0; x <= x1; x++)
    {
        float t = (x - x0) / (float)(x1 - x0);
        int y = y0 + (y1 - y0) * t;
        if (steep)
        {
            image.set(y, x, color); // if transposed, de−transpose
        }
        else
        {
            image.set(x, y, color);
        }
    }
}

void Renderer::renderPoints(vector<Vertex> vertexs, int width, int heigth, TGAImage &image, TGAColor color)
{
    int w = width / 2;
    int h = heigth / 2;
    float x, y;
    for (size_t i = 0; i < vertexs.size(); i++)
    {
        Vertex v = vertexs.at(i);
        x = v.getX() * w + w;
        y = v.getY() * h + h;
        image.set(x, y, color);
    }
}

void Renderer::renderTriangles(vector<Triangle> triangles, int width, int heigth, TGAImage &image, TGAColor color)
{
    int w = width / 2;
    int h = heigth / 2;
    for (size_t i = 0; i < triangles.size(); i++)
    {
        Triangle t = triangles.at(i);
        for (size_t i = 0; i < 3; i++)
        {
            Vertex v0 = t.getPoint(i);
            Vertex v1 = t.getPoint((i + 1) % 3);
            int x0 = v0.getX() * w + w;
            int y0 = v0.getY() * h + h;
            int x1 = v1.getX() * w + w;
            int y1 = v1.getY() * h + h;
            line(x0, y0, x1, y1, image, color);
        }
    }
}

void Renderer::createBoundingBox(Triangle t)
{
    float xmin = t.getPoint(0).getX();
    float ymin = t.getPoint(0).getY();
    float xmax = t.getPoint(0).getX();
    float ymax = t.getPoint(0).getY();

    // Changer pour std::min std::max
    for (size_t i = 1; i < 3; i++)
    {
        Vertex v = t.getPoint(i);
        if (v.getX() < xmin)
            xmin = v.getX();
        if (v.getY() < ymin)
            ymin = v.getY();
        if (v.getX() > xmax)
            xmax = v.getX();
        if (v.getY() > ymax)
            ymax = v.getY();
    }
    // Associer la face et la box
    boxes.push_back(BoundingBox(xmin, ymin, xmax, ymax));
}

void Renderer::renderBoxes(vector<Triangle> triangles, int width, int heigth, TGAImage &image, TGAColor color)
{
    for (size_t i = 0; i < triangles.size(); i++)
    {
        Triangle t = triangles.at(i);
        createBoundingBox(t);
        renderBox(boxes.at(i), width, heigth, image, color);
    }
}

void Renderer::renderBox(BoundingBox b, int width, int heigth, TGAImage &image, TGAColor color)
{
    int w = width / 2;
    int h = heigth / 2;
    for (size_t i = 0; i < 4; i++)
    {
        Vertex v0 = b.getPoint(i);
        Vertex v1 = b.getPoint((i + 1) % 4);
        int x0 = v0.getX() * w + w;
        int y0 = v0.getY() * h + h;
        int x1 = v1.getX() * w + w;
        int y1 = v1.getY() * h + h;
        line(x0, y0, x1, y1, image, color);
    }
}