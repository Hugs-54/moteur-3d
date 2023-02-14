#include "parser.h"

Parser::Parser() {}

void Parser::parse(string fileName, int width, int heigth, double dstZ)
{
    fstream file;
    file.open(fileName, ios::in);
    string line, tmp;
    while (getline(file, line))
    {
        istringstream stream(line);
        if (!line.compare(0, 2, "v "))
        {
            vector<string> numbers;
            while (getline(stream, tmp, ' '))
            {
                numbers.push_back(tmp);
            }
            float x = stof(numbers.at(1));
            float y = stof(numbers.at(2));
            float z = stof(numbers.at(3));
            Vertex v(x, y, z);
            points.push_back(v);
        }
        else if (!line.compare(0, 2, "f "))
        {
            vector<string> tuples;
            while (getline(stream, tmp, ' '))
            {
                tuples.push_back(tmp);
            }
            Tuple t1 = parseTuple(tuples.at(1));
            Tuple t2 = parseTuple(tuples.at(2));
            Tuple t3 = parseTuple(tuples.at(3));
            Triangle tri(width, heigth, t1.getI1(), t2.getI1(), t3.getI1(), t1.getI2(), t2.getI2(), t3.getI2());
            triangles.push_back(tri);
        }
        else if (!line.compare(0, 2, "vt"))
        {
            vector<string> n;
            while (getline(stream, tmp, ' '))
            {
                n.push_back(tmp);
            }
            float x = stof(n.at(2));
            float y = stof(n.at(3));
            Vertex v(x, y, 0);
            pointsTextures.push_back(v);
        }
    }
    file.close();
}

Tuple Parser::parseTuple(string t)
{
    string tmp;
    vector<int> integers;
    stringstream stream(t);
    while (getline(stream, tmp, '/'))
    {
        integers.push_back(stoi(tmp));
    }
    Tuple tu(points.at(integers.at(0) - 1), pointsTextures.at(integers.at(1) - 1), integers.at(2));
    return tu;
}

vector<Vertex> Parser::getPoints()
{
    return points;
}

vector<Triangle> Parser::getTriangles()
{
    return triangles;
}

Vertex Parser::project(Vertex &v, double distance_z)
{
    Matrix matrix, identity;
    identity = matrix.identify(4);
    identity[3][2] = -1 / distance_z;
    matrix = Matrix(4, 1);
    matrix[0][0] = v.getX();
    matrix[1][0] = v.getY();
    matrix[2][0] = v.getZ();
    matrix[3][0] = double(1);
    matrix = identity * matrix;
    Vertex vect = matrix.matrixToVertex();
    return vect;
}
