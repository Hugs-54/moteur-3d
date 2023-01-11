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
    Renderer renderer;
    Parser parser;
    parser.parse("../resources/african_head.obj");
    // renderer.renderPoints(parser.getPoints(), width, heigth, image, red);
    renderer.renderTriangles(parser.getTriangles(), width, heigth, image, red);
    // renderer.renderBoxes(parser.getFaces(), width, heigth, image, white);
    image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
    image.write_tga_file("output.tga");
    return 0;
}
