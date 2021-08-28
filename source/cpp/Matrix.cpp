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

// enhanced matrix render function
void Matrix::render()
{
    // iterate over rows
    for (int i = 0; i < this->rows; i++)
    {
        // if first row, print unicode character 25DC in yellow color
        if (i == 0)
        {
            cout << "\033[1;33m"
                 //<< "\u25DC"
                 << "/"
                 << "\033[0m";
        }
        // if last row, print unicode character 25DF in yellow color
        else if (i == this->rows - 1)
        {
            cout << "\033[1;33m"
                 //<< "\u25DF"
                 << "\\"
                 << "\033[0m";
        }
        // otherwise, just print yellow pipe
        else
        {
            cout << "\033[1;33m"
                 << "|"
                 << "\033[0m";
        }

        // step one tab
        cout << "\t";

        // iterate over columns
        for (int j = 0; j < this->cols; j++)
        {
            // if last column make color green
            if (j == this->cols - 1)
            {
                cout << "\033[1;32m" << this->data[i * this->cols + j] << "\033[0m";
            }
            // else make color white
            else
            {
                cout << "\033[1;37m" << this->data[i * this->cols + j] << "\033[0m";
            }
            // step one tab
            cout << "\t";
        }

        // if first row, print unicode character 25DD in yellow color
        if (i == 0)
        {
            cout << "\033[1;33m"
                 //<< "\u25DD"
                 << "\\"
                 << "\033[0m";
        }
        // if last row, print unicode character 25DE in yellow color
        else if (i == this->rows - 1)
        {
            cout << "\033[1;33m"
                 //<< "\u25DE"
                 << "/"
                 << "\033[0m";
        }
        // otherwise, just print yellow pipe
        else
        {
            cout << "\033[1;33m"
                 << "|"
                 << "\033[0m";
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

// Multiply row by a scalar
void Matrix::multiplyRow(int row, double scalar)
{
    for (int i = 0; i < this->cols; i++)
    {
        this->set(row, i, this->get(row, i) * scalar);
    }
}
