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