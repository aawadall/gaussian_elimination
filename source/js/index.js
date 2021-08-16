const ref = require("./gaussian_elimination").gaussianElimination;

let A = [
    [2, 1, -1, 8], [-3, -1, 2, -11], [-2, 1, 2, -3]];

    console.log(A.length);
    console.log(A);
    let A_prime = ref(A);
    console.log(A_prime);

