// Matrix Class
//

#include <vector>
using std::vector;

class Matrix
{
private:
    int rows, cols;
    std::vector<double> data;

public:
    Matrix(int rows, int cols);
    void set(int row, int col, double value);
    double get(int row, int col);
    int getRows();
    int getCols();
    void print();
    void render();
    void swapRows(int row1, int row2);
    void addWightedRow(int i, int j, double multiplier);
    void multiplyRow(int row, double multiplier);
    Matrix operator=(Matrix &matrix);
};