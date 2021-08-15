

# Gaussian Elimination
Different implementations of the gaussian elimination method.

## [PseudoCode](./pseudocode/gaussian_elimination.md)

below is the pseudo code for the gaussian elimination method on a matrix A.
_Source : https://en.wikipedia.org/wiki/Gaussian_elimination_

### Initialization 

get dimensions of A

$$m,n \gets dim(\bold{A}) \\$$ 

Copy A to A prime 

$$\bold{A^{'}} \gets \bold{A} \\ $$


initiliase the pivot row and pivot column

$$h \gets 1 , k \gets 1$$


### Main Loop
Loop until the pivot row is the last row

$$\text{while: } (h \leq m \land k \leq n): $$

Find kth pivot element

$$ i_{max} \gets \underset{i \in [h \ldots m]}\argmax{\mid a^{'}_{i,k}\mid}$$ 

If no pivot in this column, pass to next column, 

$$if a^{'}_{i_{max}, k} = 0 \\$$
$$\quad k \gets k+1 \\$$

other wise swap the pivot row and the current row

$$else \\$$
$$\quad \text{swap: } a^{'}_{i_{max}, k} \gets a^{'}_{h, k} \\$$

do for all rows below pivot 

$$\forall i \in [h + 1 \ldots i_{max}]: \\ $$

$$ f \gets \frac{a^{'}_{i, k}}{a^{'}_{h, k}}$$


Fill with zeros the row below the pivot row

$$a^{'}_{i, k} \gets 0$$

Do for all remaining elements in current row 

$$\forall j \in [k + 1 \ldots n] : \\$$
$$a^{'}_{i, j} \gets a^{'}_{i, j} - f a^{'}_{h, j}$$

advance pivot row and column

$$h \gets h +1, k \gets k +1$$ 

<script async src="https://cdn.jsdelivr.net/npm/mathjax@2/MathJax.js?config=TeX-AMS-MML_CHTML"></script>
