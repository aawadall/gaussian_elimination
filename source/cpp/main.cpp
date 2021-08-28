/**
 * A Program implementing Gaussian Elimination
 */
#ifndef MATRIX_DEFINITION
#define MATRIX_DEFINITION
#include "Matrix.h"
#endif
#include "GaussElimination.h"
#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{

    // Prepare Test Matrix
    /**
     * A =  [[  2,   1,  -1,   8], 
     *       [ -3,  -1,   2, -11], 
     *       [ -2,   1,   2,  -3]];
     */

    auto A = Matrix(3, 4);
    // row 1
    A.set(0, 0, 2);
    A.set(0, 1, 1);
    A.set(0, 2, -1);
    A.set(0, 3, 8);
    // row 2
    A.set(1, 0, -3);
    A.set(1, 1, -1);
    A.set(1, 2, 2);
    A.set(1, 3, -11);
    // row 3
    A.set(2, 0, -2);
    A.set(2, 1, 1);
    A.set(2, 2, 2);
    A.set(2, 3, -3);

    // Print the Test Matrix
    cout << "Test Matrix A:" << endl;
    A.print();

    // Gaussian Elimination
    cout << "Gaussian Elimination..." << endl;
    auto B = GaussElimination(A);

    // Print the Solution Matrix
    cout << "Solution Matrix B:" << endl;
    B.print();

    // RREF
    cout << "RREF..." << endl;
    auto C = ReducedRowEchelonForm(A);
    cout << "Solution Matrix C:" << endl;
    C.print();

    return 0;
}
