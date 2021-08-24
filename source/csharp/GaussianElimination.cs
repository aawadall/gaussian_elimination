namespace csharp
{
    /// <summary>
    /// Gaussian elimination algorithm.
    /// </summary>
    public static class GaussianElimination
    {
        public static Matrix GaussianEliminate(this Matrix matrix)
        {
            Matrix A = matrix.MakeCopy();

            // Iterate over all rows 
            for (int i = 0; i < A.Rows; i++)
            {
                // If the pivot element is zero, swap with a lower row
                if (A[i, i] == 0)
                {
                    for (int x = i + 1; x < A.Rows; x++)
                    {
                        if (A[x, i] != 0)
                        {
                            A.SwapRows(i, x);
                            break;
                        }
                    }
                }
                // Zero elements below the pivot except for last pivot
                if (i < A.Rows - 1)
                {
                    for (int x = i + 1; x < A.Rows; x++)
                    {
                        // find multiplier
                        double multiplier = -A[x, i] / A[i, i];
                        // add to weighted row
                        A.AddWeightedRow(i, x, multiplier);
                    }
                }
            }

            return A;
        }
    }
}