#include "renderer.h"
#include <iostream>

Renderer::Renderer(int w, int h) : width{w}, heigth{h}
{
}

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

void Renderer::renderPoints(vector<Vertex> vertexs, TGAImage &image, TGAColor color)
{
    float x, y;
    for (size_t i = 0; i < vertexs.size(); i++)
    {
        Vertex v = vertexs.at(i);
        x = v.getPixelX();
        y = v.getPixelY();
        image.set(x, y, color);
    }
}

void Renderer::renderTriangles(vector<Triangle> triangles, TGAImage &image, TGAColor color)
{
    for (size_t i = 0; i < triangles.size(); i++)
    {
        Triangle t = triangles.at(i);
        for (size_t i = 0; i < 3; i++)
        {
            Vertex v0 = t.getPoint(i);
            Vertex v1 = t.getPoint((i + 1) % 3);
            int x0 = v0.getPixelX();
            int y0 = v0.getPixelY();
            int x1 = v1.getPixelX();
            int y1 = v1.getPixelY();
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

    BoundingBox bb(xmin, ymin, xmax, ymax, width, heigth);
    boxAndTriangle.push_back(BoxAndTriangle(t, bb));
    boxes.push_back(bb);
}

vector<int> Renderer::createBox(Triangle t)
{
    int xmin = t.getPoint(0).getPixelX();
    int ymin = t.getPoint(0).getPixelY();
    int xmax = t.getPoint(0).getPixelX();
    int ymax = t.getPoint(0).getPixelY();

    for (size_t i = 1; i < 3; i++)
    {
        Vertex v = t.getPoint(i);
        if (v.getPixelX() < xmin)
            xmin = v.getPixelX();
        if (v.getPixelY() < ymin)
            ymin = v.getPixelY();
        if (v.getPixelX() > xmax)
            xmax = v.getPixelX();
        if (v.getPixelY() > ymax)
            ymax = v.getPixelY();
    }
    vector<int> p = {xmin,xmax,ymin,ymax};
    return p;
}

void Renderer::renderBoxes(vector<Triangle> triangles, TGAImage &image, TGAColor color)
{
    createBoxes(triangles);
    for (size_t i = 0; i < triangles.size(); i++)
    {
        renderBox(boxes.at(i), image, color);
    }
}

void Renderer::createBoxes(vector<Triangle> triangles)
{
    for (size_t i = 0; i < triangles.size(); i++)
    {
        Triangle t = triangles.at(i);
        createBoundingBox(t);
    }
}

void Renderer::renderBox(BoundingBox b, TGAImage &image, TGAColor color)
{
    for (size_t i = 0; i < 4; i++)
    {
        Vertex v0 = b.getPoint(i);
        Vertex v1 = b.getPoint((i + 1) % 4);
        int x0 = v0.getPixelX();
        int y0 = v0.getPixelY();
        int x1 = v1.getPixelX();
        int y1 = v1.getPixelY();
        line(x0, y0, x1, y1, image, color);
    }
}

void Renderer::fillTriangles(vector<Triangle> triangles, TGAImage &image)
{
    for (size_t k = 0; k < triangles.size(); k++)
    {
        Triangle t = triangles.at(k);
        vector<int> p = createBox(t);
        
        Vertex& v1 = t.getPoint(0);
        Vertex& v2 = t.getPoint(1);
        Vertex& v3 = t.getPoint(2);
        v1.setColor(randomize_color());
        v2.setColor(randomize_color());
        v3.setColor(randomize_color());

        // Pour chaque pixel de la boite
        for (int i = p.at(0); i < p.at(1); i++)
        {
            for (int j = p.at(2); j < p.at(3); j++)
            {
                // Si pixel dans le triangle alors remplir
                if (isPointInsideTriangle(t, i, j))
                {
                    image.set(i, j, t.getPoint(0).getColor());
                }
            }
        }
    }
}

TGAColor Renderer::randomize_color()
{
    std::random_device rd;
    std::default_random_engine engine(rd());
    std::uniform_int_distribution<int> distr(0, 255);
    return TGAColor(distr(engine), distr(engine), distr(engine), 255);
}

float Renderer::areaOfTriangle(Vertex v1, Vertex v2, Vertex v3)
{
    float x1 = v1.getPixelX();
    float x2 = v2.getPixelX();
    float x3 = v3.getPixelX();
    float y1 = v1.getPixelY();
    float y2 = v2.getPixelY();
    float y3 = v3.getPixelY();
    return (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0;
}

bool Renderer::isPointInsideTriangle(Triangle& t, float px, float py)
{
    Vertex& v1 = t.getPoint(0);
    Vertex& v2 = t.getPoint(1);
    Vertex& v3 = t.getPoint(2);
    Vertex v4(px, py, 0);
    v4.setPixel(px, py);

    float A = areaOfTriangle(v1, v2, v3);
    float A1 = areaOfTriangle(v4, v2, v3);
    float A2 = areaOfTriangle(v1, v4, v3);
    float A3 = areaOfTriangle(v1, v2, v4);

    double alpha = (double)A2/(double)A;
    double beta  = (double)A3/(double)A;
    double gamma = (double)A1/(double)A;

    v1.setComponent(alpha);
    v2.setComponent(beta);
    v3.setComponent(gamma);

    return alpha>-0.01 && beta>-0.01 && gamma>-0.01;
}