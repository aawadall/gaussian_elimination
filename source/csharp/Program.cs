/// <summary>
/// This is C# implementation of the Gaussian Elimination algorithm.
/// </summary>
using System;

namespace csharp
{
    class Program
    {
        static void Main(string[] args)
        {
            // Prepare Test Matrix
            /**
            * A =  [[  2,   1,  -1,   8], 
            *       [ -3,  -1,   2, -11], 
            *       [ -2,   1,   2,  -3]];
            */

            Matrix A = new Matrix(3, 4);
            // Row 1
            A[0, 0] = 2;
            A[0, 1] = 1;
            A[0, 2] = -1;
            A[0, 3] = 8;
            // Row 2
            A[1, 0] = -3;
            A[1, 1] = -1;
            A[1, 2] = 2;
            A[1, 3] = -11;
            // Row 3
            A[2, 0] = -2;
            A[2, 1] = 1;
            A[2, 2] = 2;
            A[2, 3] = -3;

            // Print Test Matrix
            Console.WriteLine("Test Matrix A:");
            A.Print();

            // Calculate Gaussian Elimination
            Matrix B = A.GaussianEliminate();

            // Print Result Matrix
            Console.WriteLine("Result Matrix B:");
            B.Print();


        }
    }
}
