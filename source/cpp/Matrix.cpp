#include "Matrix.h"
#include <iostream>
using std::cout;
using std::endl;

// Constructor
Matrix::Matrix(int rows, int cols)
{
    this->rows = rows;
    this->cols = cols;
    for (int i = 0; i < rows * cols; i++)
    {
        data.push_back(0);
    }
}

// Get Rows
int Matrix::getRows()
{
    return this->rows;
}

// Get Columns
int Matrix::getCols()
{
    return this->cols;
}

// Set individual element
void Matrix::set(int row, int col, double value)
{
    this->data[row * this->cols + col] = value;
}

// Get individual element
double Matrix::get(int row, int col)
{
    return this->data[row * this->cols + col];
}

// Print matrix
void Matrix::print()
{
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            cout << this->data[i * this->cols + j] << "\t";
        }
        cout << endl;
    }
}

// Copy assigment operator
Matrix Matrix::operator=(Matrix &rhs)
{
    int rows = rhs.getRows();
    int cols = rhs.getCols();

    Matrix output = Matrix(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            output.set(i, j, rhs.get(i, j));
    return output;
}

// Swap rows
void Matrix::swapRows(int row1, int row2)
{
    for (int i = 0; i < this->cols; i++)
    {
        auto temp = this->get(row1, i);
        this->set(row1, i, this->get(row2, i));
        this->set(row2, i, temp);
    }
}

// Add weighted row to another row
void Matrix::addWightedRow(int i, int j, double multiplier)
{
    for (int k = 0; k < this->cols; k++)
    {
        this->set(j, k, this->get(j, k) + this->get(i, k) * multiplier);
    }
}