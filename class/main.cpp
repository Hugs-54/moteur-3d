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
    string filename, fileTextureName, fileNormalName;
    if (argc == 2)
    {
        filename = argv[1];
        fileTextureName = "../resources/" + filename + "_diffuse.tga";
        fileNormalName = "../resources/" + filename + "_nm.tga";
        filename = "../resources/" + filename + ".obj";
    }
    else
    {
        std::cout << "Aucun argument renseigné, african_head utilisé. (argv : african_head/diablo3_pose) \n";
        fileTextureName = "../resources/african_head_diffuse.tga";
        fileNormalName = "../resources/african_head_nm.tga";
        filename = "../resources/african_head.obj";
    }

    int width = 1000;
    int height = 1000;
    TGAImage image(width, height, TGAImage::RGB);
    TGAImage texture;
    TGAImage normalmap;
    texture.read_tga_file(fileTextureName.c_str());
    texture.flip_vertically();
    normalmap.read_tga_file(fileNormalName.c_str());
    normalmap.flip_vertically();
    Parser parser;
    Renderer renderer(width, height);
    parser.parse(filename, width, height);
    float *zbuffer = new float[width * height];
    for (int i = width * height; i--; zbuffer[i] = -std::numeric_limits<float>::max())
        ;
    renderer.fillTriangles(parser.triangles, image, texture, normalmap, zbuffer);
    image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
    image.write_tga_file("output.tga");
    delete[] zbuffer;
    return 0;
}
