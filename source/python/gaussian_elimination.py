"""Gaussian Elimination Implementation in Python."""
import numpy as np


def swap(matrix, i, j):
    """Swap two rows."""
    matrix[i], matrix[j] = matrix[j], matrix[i]
    return matrix


def add_row(matrix, i, j):
    """ith row to te jth row."""
    matrix[j] += matrix[i]
    return matrix


def add_weighted_row(matrix, i, j, c):
    """Add c times row i to row j."""
    print("wighted add i,j,c => {},{},{}".format(i, j, c))
    print("matrix before =>\n", matrix)
    for k in range(len(matrix[0])):
        matrix[j, k] = matrix[j, k] + c * matrix[i, k]

    print("matrix after =>\n", matrix)
    return matrix


def multiply_row(matrix, i, c):
    """Multiply row i by c."""
    matrix[i] *= c
    return matrix


def ref(matrix):
    """attempt to implement Row Echelon Form."""
    # convert to float
    matrix = matrix.astype(float)

    n, m = len(matrix), len(matrix[0])
    print("m,n => {},{}".format(m, n))
    # iterate over rows
    for i in range(m-1):
        # if pivot is 0 swap row i and first non-zero row
        if matrix[i, i] == 0:
            for j in range(i+1, m):
                if matrix[j, i] != 0:
                    matrix = swap(matrix, i, j)
                    break

        # zero below pivot unless i = n - 1
        if i < n - 1:
            for j in range(i+1, n):
                # find multiplier
                multiplier = -matrix[j, i] / matrix[i, i]
                print("multiplier is {} for row {} from row {}".format(
                    multiplier, j, i))
                # add multiplier to current row
                matrix = add_weighted_row(matrix, i, j, multiplier)

    return matrix


def gaussian_elimination(matrix):
    """Gaussian Elimination Method"""
    m, n = len(matrix), len(matrix[0])
    h = 1
    k = 1
    while h < m and k < n:
        # find max row in column k
        i_max = np.argmax(np.abs(matrix[h:, k]))

        # if no pivot in this column, pass to next column
        if matrix[i_max, k] == 0:
            h += 1
        else:
            # swap row i_max and h
            matrix[i_max], matrix[h] = matrix[h], matrix[i_max]

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
        print(matrix)
    return matrix


def main():
    """Main function."""
    matrix = np.array([[2, 1, -1, 8], [-3, -1, 2, -11], [-2, 1, 2, -3]])
    print(matrix)
    m_prime = ref(matrix)
    print(m_prime)


if __name__ == "__main__":
    main()
