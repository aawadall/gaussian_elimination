"""Gaussian Elimination Implementation in Python."""
import numpy as np


def swap(matrix, i, j):
    """Swap rows i and j in matrix."""
    matrix[i], matrix[j] = matrix[j], matrix[i]


def gaussian_elimination(matrix):
    """Gaussian Elimination Method"""
    m, n = len(matrix), len(matrix[0])
    h = 1
    k = 1
    while h < m and k < n:
        print(h, k, m, n)
        # find max row in column k
        i_max = np.argmax(np.abs(matrix[h:, k]))
        print("i_max =", i_max)
        # if no pivot in this column, pass to next column
        if matrix[i_max, k] == 0:
            h += 1
        else:
            # swap row i_max and h
            swap(matrix, i_max, h)
            # do for all rows below i_max
            for i in range(h + 1, m):
                f = matrix[i, k] / matrix[h, k]
                # Fill with zeros the lower part of pivot column
                matrix[i, k] = 0
                # do for the remaining elements in current row
                for j in range(k+1, n):
                    matrix[i, j] -= matrix[h, j] * f
            # advance h and k
            h += 1
            k += 1
    return matrix


def main():
    """Main function."""
    matrix = np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
    print(matrix)
    print(gaussian_elimination(matrix))


if __name__ == "__main__":
    main()
