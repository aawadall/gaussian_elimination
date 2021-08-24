using System;
/// <summary>
/// Matrix class.
/// </summary>
namespace csharp
{
    public class Matrix
    {
        public int Rows { get; private set; }
        public int Columns { get; private set; }

        private double[,] _matrix;

        public Matrix(int rows, int columns)
        {
            Rows = rows;
            Columns = columns;
            _matrix = new double[Rows, Columns];
        }

        public double this[int row, int column]
        {
            get
            {
                return _matrix[row, column];
            }
            set
            {
                _matrix[row, column] = value;
            }
        }

        public Matrix MakeCopy()
        {
            Matrix copy = new Matrix(Rows, Columns);
            for (int i = 0; i < Rows; i++)
            {
                for (int j = 0; j < Columns; j++)
                {
                    copy[i, j] = _matrix[i, j];
                }
            }
            return copy;
        }

        /// <summary>
        /// Swap two rows of the matrix.
        /// </summary>
        /// <param name="row1"></param>
        /// <param name="row2"></param>
        public void SwapRows(int row1, int row2)
        {
            for (int i = 0; i < Columns; i++)
            {
                double temp = _matrix[row1, i];
                _matrix[row1, i] = _matrix[row2, i];
                _matrix[row2, i] = temp;
            }
        }

        /// <summary>
        /// Add row one multiplied by weight to row two.
        /// </summary>
        /// <param name="row1"></param>
        /// <param name="row2"></param>
        /// <param name="weight"></param>
        public void AddWeightedRow(int row1, int row2, double weight)
        {
            for (int i = 0; i < Columns; i++)
            {
                _matrix[row2, i] += _matrix[row1, i] * weight;
            }
        }

        /// <summary>
        /// Print the matrix.
        /// </summary>
        public void Print()
        {
            for (int i = 0; i < Rows; i++)
            {
                for (int j = 0; j < Columns; j++)
                {
                    Console.Write(_matrix[i, j] + "\t");
                }
                Console.WriteLine();
            }
        }
    }
}