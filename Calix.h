#ifndef CALIX
#define CALIX

#include <iostream>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <utility>

using namespace std;

class Calix{
public :
    // Constructors
    Calix();
    Calix(double** matrix);

    // Row Operations
    void switchRows(int row_int, int row_new , double** matrix);
    void addRow_Row(double c ,int row_int, int row_new , double** matrix, int n);
    void multRow(double c ,int row, double** matrix, int n);

    // Display
    void displayMatrix(double** matrix, int n);
    void displayMatrix(double** matrix, int n, int m);

    // Linear Display
    void displayLinearMatrix(double** matrix, double* sol, int n);
    void displayLinearMatrix(double** matrix, double* sol, int n, int m);

    // Matrix Operations
    double** matrixSum();
    void matrixMult(); // TODO
    double** transposMatrix(double** matrix, int row, int col);

    // Serial Operations
        // Determinant
    void determinant();
    double determinantCal(double** matrix, int n);
    double coFactorCal(double** matrix, int n, int row, int col);
        // Adjoint
    void adjoint();
    double** adjMatrixCal(double** matrix, int n);
        // Cramer
    void cramer();
    double** cramerCalc();
        // L*U = T
    void ALU();
    double** ALUCal(double** matrix, int n);

    void makeEchollon(double** matrix, double** matrixRev, int n);
    void matRev();
};

#endif // CALIX

