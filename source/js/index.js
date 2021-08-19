const GaussianElimination = require("./gaussian_elimination");

console.log(GaussianElimination)
let A = [
    [2, 1, -1, 8], 
    [-3, -1, 2, -11], 
    [-2, 1, 2, -3]];

    
    console.log(A);
    let A_prime =  GaussianElimination.gaussianElimination(A);
    console.log(A_prime);

