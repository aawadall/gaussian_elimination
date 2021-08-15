

# Gaussian Elimination
Different implementations of the gaussian elimination method.

## [PseudoCode](./pseudocode/gaussian_elimination.md)

below is the pseudo code for the gaussian elimination method on a matrix A.
_Source : https://en.wikipedia.org/wiki/Gaussian_elimination_

### Initialization 

get dimensions of A 

![f1](https://quicklatex.com/cache3/4f/ql_722fd05313eb5c38f2d4d1e6e1f0424f_l3.png)


Copy A to A prime 

![f2](https://quicklatex.com/cache3/79/ql_ab0edcfe244f85689bc5683bcead6a79_l3.png)


initiliase the pivot row and pivot column

![f3](https://quicklatex.com/cache3/eb/ql_62f9bad2ac8ee85c235cb1a310f35beb_l3.png)


### Main Loop
Loop until the pivot row is the last row

![f4](https://quicklatex.com/cache3/82/ql_699839e51493524b06dbb6d8702c7882_l3.png)


Find kth pivot element

![f5](https://quicklatex.com/cache3/50/ql_08b88277d33a36743518aa2b6933b650_l3.png)

If no pivot in this column, pass to next column, 

![f6](https://quicklatex.com/cache3/ff/ql_55b59b1c2ac9a9e8c9ee9f2beb5400ff_l3.png)

other wise swap the pivot row and the current row

![f7](https://quicklatex.com/cache3/20/ql_8aee23cac4a526797a8e42ed0a0b3c20_l3.png)

do for all rows below pivot 

![f8](https://quicklatex.com/cache3/f0/ql_e9ba90e6e4275e9183c4d520622ee9f0_l3.png)

Fill with zeros the row below the pivot row

![f9](https://quicklatex.com/cache3/88/ql_760a0db3692f47955466c6bd5e004288_l3.png)

Do for all remaining elements in current row 

![f10](https://quicklatex.com/cache3/fe/ql_7233094612d5872349128252e3bf9cfe_l3.png)

advance pivot row and column

![f11](https://quicklatex.com/cache3/b4/ql_6f38f5e4bf6f31a0b9b205392f0689b4_l3.png)

