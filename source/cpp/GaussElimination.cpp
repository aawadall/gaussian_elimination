#include "GaussElimination.h"

Matrix GaussElimination(Matrix &matrix)
{
    auto A = matrix;
    int m = A.getCols();
    int n = A.getRows();

    // iterate over rows
    for (int i = 0; i < n; i++)
    {

        // if pivot is zero, swap rows
        if (A.get(i, i) == 0)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (A.get(j, i) != 0)
                {
                    A.swapRows(i, j);
                    break;
                }
            }
        }
        // zero below pivot unless i = n - 1
        for (int j = i + 1; j < n; j++)
        {
            // find multiplier
            double multiplier = -A.get(j, i) / A.get(i, i);
            // add wighted rows
            A.addWightedRow(i, j, multiplier);
        }
    }
    return A;
}

// Reduced Row Echelon Form
Matrix ReducedRowEchelonForm(Matrix &matrix)
{

    // Make Upper Triangular
    auto A = GaussElimination(matrix);

    // Make Lower Triangular
    // iterate over pivots from 1 to n
    for (int i = 1; i < A.getRows(); i++)
    {
        // zero above pivot
        for (int j = 0; j < i; j++)
        {
            // find multiplier
            double multiplier = -A.get(j, i) / A.get(i, i);
            // add wighted rows
            A.addWightedRow(i, j, multiplier);
        }
    }

    // Make Diagonal 1
    for (int i = 0; i < A.getRows(); i++)
    {
        // find multiplier
        double multiplier = 1 / A.get(i, i);
        // multiply row by multiplier
        A.multiplyRow(i, multiplier);
    }
    return A;
}