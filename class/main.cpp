#include "renderer.h"
#include "tgaimage.h"
#include "parser.h"
#include <iostream>
#include <fstream>

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);
const TGAColor green = TGAColor(0, 255, 0, 255);
const TGAColor blue = TGAColor(0, 0, 255, 255);
using namespace std;

int main(int argc, char **argv)
{
    int width = 1000;
    int height = 1000;
    TGAImage image(width, height, TGAImage::RGB);
    Parser parser;
    Renderer renderer(width, height);
    parser.parse("../resources/african_head.obj", width, height);
    // renderer.renderTriangles(parser.getTriangles(), image, red);
    // renderer.renderPoints(parser.getPoints(), image, blue);
    // renderer.renderBoxes(parser.getTriangles(), image, white);
    float *zbuffer = new float[width * height];
    for (int i = width * height; i--; zbuffer[i] = -std::numeric_limits<float>::max())
        ;
    renderer.fillTriangles(parser.triangles, image, zbuffer);
    image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
    image.write_tga_file("output.tga");
    return 0;
}
