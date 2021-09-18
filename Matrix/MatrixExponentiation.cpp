//:::: Alien :::://
// Muhammad Eid //
#include <bits/stdc++.h>
using namespace std;

struct Matrix {
    vector<vector<int>> matrix;
    int rows = 0, cols = 0;

    Matrix (int _rows, int _cols) {
        rows = _rows;
        cols = _cols;
        matrix = vector<vector<int>>(rows, vector<int>(cols));
    }
    
    Matrix (vector<vector<int>> _matrix) {
        matrix = _matrix;
        rows = matrix.size();
        cols = matrix[0].size();
    }

    void scanMatrix() {
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                cin >> matrix[i][j];
    }

    void printMatrix() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j)
                cout << matrix[i][j] << ' ';
            cout << '\n';
        }
    }

    void identityMatrix() {
        for (int i = 0; i < rows; ++i)
            matrix[i][i] = 1;
    }

    Matrix operator* (Matrix other) {
        Matrix ret(rows, other.cols);
        if (cols != other.rows) return ret;

        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.cols; ++j)
                for (int k = 0; k < cols; ++k)
                    ret.matrix[i][j] += matrix[i][k] * other.matrix[k][j];

        return ret;
    }
};

Matrix matrixPower(Matrix mat, int p) {
    Matrix ret(mat.rows, mat.cols);
    ret.identityMatrix();
    while (p) {
        if (p & 1) ret = ret * mat;
        mat = mat * mat;
        p >>= 1;
    }
    return ret;
}

int main() {

    int r1, c1; cin >> r1 >> c1;
    Matrix A(r1, c1);
    A.scanMatrix();
    A = matrixPower(A, 2);
    A.printMatrix();

return 0;
}
