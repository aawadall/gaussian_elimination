# Gaussian Elimination
Different implementations of the gaussian elimination method.

## [PseudoCode](./pseudocode/gaussian_elimination.md)




below is the pseudo code for the gaussian elimination method.
```math
h \gets 1 ,
k \gets 1 \\
\textrm{while:} (h \leq m \land k \leq n) \\

    i_{max} \gets argmax(i = h \ldots m, \mid \bold{A}[i, k] \mid) \\
    if A[i_{max}, k] = 0 \\
        \textrm{/* No pivot in this column, pass to next column */} \\
        k \gets k+1 \\
    else \\
         \text{swap rows}(h, i_{max}) \\
         /* Do for all rows below pivot: */ \\
         for i \in [h + 1 \ldots m]: \\
             f := A[i, k] / A[h, k] \\
             /* Fill with zeros the lower part of pivot column: */ \\
             A[i, k] \gets 0 \\
             /* Do for all remaining elements in current row: */ \\
             for j \in [k + 1 \ldots n]: \\
                 A[i, j] \gets A[i, j] - A[h, j] * f \\
         /* Increase pivot row and column */ \\
         h \gets h + 1 \\
         k \gets k + 1 \\

```

_Source : https://en.wikipedia.org/wiki/Gaussian_elimination_