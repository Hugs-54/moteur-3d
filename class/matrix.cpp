#include "matrix.h"
#include <iostream>

Matrix::Matrix(const int rows, const int cols) : m_rows{rows}, m_cols{cols}, m_matrix{std::vector<std::vector<double>>(rows, std::vector<double>(cols, 0))}
{
}

Matrix::Matrix(Vertex v) : m_rows(4), m_cols(1), m_matrix{std::vector<std::vector<double>>(4, std::vector<double>(1, 1.))}
{
    m_matrix[0][0] = v.getX();
    m_matrix[1][0] = v.getY();
    m_matrix[2][0] = v.getZ();
}

std::vector<double> &Matrix::operator[](const int i)
{
    assert(i >= 0 && i < m_rows);
    return m_matrix[i];
}

int Matrix::getNbCols() const
{
    return m_cols;
}

int Matrix::getNbRows() const
{
    return m_rows;
}

Matrix Matrix::identify(const int dimension)
{
    Matrix temp(dimension, dimension);

    for (int i = 0; i < dimension; i++)
    {
        for (int j = 0; j < dimension; j++)
        {
            temp[i][j] = (i == j);
        }
    }
    return temp;
}

Matrix Matrix::operator*(const Matrix &other)
{
    assert(m_cols == other.getNbRows());
    int cols = other.getNbCols();

    Matrix temp(m_rows, cols);
    for (int i = 0; i < m_rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            temp.m_matrix[i][j] = 0.f;

            for (int k = 0; k < m_cols; k++)
            {
                temp.m_matrix[i][j] += m_matrix[i][k] * other.m_matrix[k][j];
            }
        }
    }
    return temp;
}

std::ostream &operator<<(std::ostream &s, Matrix &m)
{
    for (int i = 0; i < m.getNbRows(); i++)
    {
        for (int j = 0; j < m.getNbCols(); j++)
        {
            s << m[i][j];
            if (j < m.getNbCols() - 1)
                s << "\t";
        }
        s << "\n";
    }
    return s;
}

Vertex Matrix::matrixToVertex()
{
    double z = m_matrix[3][0];
    return Vertex(m_matrix[0][0] / z, m_matrix[1][0] / z, m_matrix[2][0] / z);
}