#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <vector>
// Every operation is defined on matrix?
// Objects like distributions cant?
// Type checking ???
// Matrix division makes no sense
// max of matrix? - default as euclidean for scalars?
// use std::any for functions - catch bad_cast expcetion

class Matrix
{
private:
    int rows;
    int cols;
    std::vector<std::vector<float>> matrix;
    bool isComplex;
    
    /* data */
public:
    Matrix(/* args */);
    ~Matrix();
    bool const isRowVector();

    bool const isColVector();

    bool const isScalar();

    bool const isMultiplicable(Matrix a);

    Matrix const multiply(Matrix a);

    Matrix const add(Matrix a);

    Matrix const power(Matrix a);

    bool const isEqual();

};

Matrix::Matrix(/* args */)
{
}

Matrix::~Matrix()
{
}


#endif