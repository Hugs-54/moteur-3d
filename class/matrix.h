#ifndef __MATRIX_H__
#define __MATRIX_H__

#undef NDEBUG
#include <cassert>
#include <vector>
#include "vertex.h"

const int SIZE = 4;

class Matrix
{
private:
    int m_rows;
    int m_cols;
    std::vector<std::vector<double>> m_matrix;
    friend std::ostream &operator<<(std::ostream &s, Matrix &m);

public:
    explicit Matrix(const int rows = SIZE, const int cols = SIZE);
    Matrix(Vertex v);
    int getNbCols() const;
    int getNbRows() const;
    std::vector<double> &operator[](const int i);
    Matrix operator*(const Matrix &other);
    static Matrix identify(const int dimension);
    Vertex matrixToVertex();
};

#endif //__MATRIX_H__