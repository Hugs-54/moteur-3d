#include "tgaimage.h"
#include "renderer.h"
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
    int heigth = 1000;
    TGAImage image(width, heigth, TGAImage::RGB);
    Parser parser;
    Renderer renderer(width, heigth);
    parser.parse("../resources/african_head.obj", width, heigth);
    // renderer.renderTriangles(parser.getTriangles(), image, red);
    // renderer.renderPoints(parser.getPoints(), image, blue);
    // renderer.renderBoxes(parser.getTriangles(), image, white);
    renderer.fillTriangles(parser.getTriangles(), image);
    image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
    image.write_tga_file("output.tga");
    return 0;
}
