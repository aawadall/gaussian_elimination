/**
 * Gaussian Elimination
 */ 

const debug = true;
class GaussianElimination {

    // add weighted row to row i
    addWeightedRow = (A, j, i, multiplier) => {
        const m = A.length;
        const n = A[0].length;
        for (let k = 0; k < n; k++) {
            A[i][k] += multiplier * A[j][k];
        }
        return A;
    }

    // swap rows
    static swapRows(A, i, j) {
        if(debug) {
            console.log("swapRows(" + i + ", " + j + ")");
            console.log("A => ");
            console.log(A);
        }
        const m = A.length;
        const n = A[0].length;
        for (let k = 0; k < n; k++) {
            const temp = A[i][k];
            A[i][k] = A[j][k];
            A[j][k] = temp;
        }

        if(debug) {
            console.log("A => ");
            console.log(A);
        }
        return A;
    }

    // Gaussian Elimination
    static gaussianElimination(A) {
        const m = A.length;
        const n = A[0].length;
        if(debug) {
            console.log('A: ' + A);
            console.log('m: ' + m);
            console.log('n: ' + n);
        }
        // iterate over rows
        for (var i = 0; i < m; i++) {
            // if pivot is zero, swap rows
            if (A[i][i] === 0) {
                for(var j = i + 1; j < m; j++) {
                    if (A[j][i] !== 0) {
                        // swap rows
                        A = swapRows(A, i, j);
                        
                        break;
                    }
                }
            }

            // zero below pivot unless i = n -1
            if(i < n - 1) {
                for (var j = i + 1; j < m; j++) {
                    // find multiplier 
                    if(debug) {
                        console.log(`i= ${i}, j= ${j}`);
                        console.log('A[' + i + '][' + j + '] = ' + A[i][j]);
                        console.log('A[' + j + '][' + i + '] = ' + A[j][i]);
                    }
                    var multiplier = A[j][i] / A[i][i];

                    if(debug) {
                        console.log('multiplier: ' + multiplier);
                        console.log(A);
                    }
                    // add weighted row to row j
                    addWeightedRow(A, i, j, -multiplier);
                    
                    
                }
            }
        }
        return A;
    }
}

module.exports = GaussianElimination;