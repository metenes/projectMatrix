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


void switchRows(int row_int, int row_new , double** matrix){
    double* temp = *(matrix + row_int);
    *(matrix + row_int) = *(matrix + row_new);
    *(matrix + row_new) = temp;
}

void addRow_Row(double c ,int row_int, int row_new , double** matrix, int n){
    for(int i = 0; i < n; i++){
        *(*(matrix + row_new)+i) = c*( *(*(matrix + row_int)+i) ) + ( *(*(matrix + row_new)+i) );
    }
}

// Same funct but no const multipication
void addRow_Row(int row_int, int row_new , double** matrix, int n){
    for(int i = 0; i < n; i++){
        *(*(matrix + row_new)+i) = ( *(*(matrix + row_int)+i) ) + ( *(*(matrix + row_new)+i) );
    }
}

void multRow(double c ,int row, double** matrix, int n){
    for(int i = 0; i < n; i++){
        *(*(matrix + row)+i) = c *( *(*(matrix + row)+i) );
    }
}

void displayMatrix(double** matrix, int n){
    for(int i = 0; i < n; i++){
        cout<<"| ";
        for(int j = 0; j < n-1; j++){
            cout << matrix[i][j] << " ";
        }
        cout << matrix[i][n-1] << " |" <<endl;
    }
}

void makeEchollon(double** matrix, int n){
    if(matrix[0][0] == 0){
        cout << "Can not make Echollon matrix due to first element is 0" << endl;
        return;
    }
    else if(matrix[0][0] != 1 ){
        multRow(1/matrix[0][0], 0, matrix, n);
    }

    // columns
    for(int i = 0 ; i < n; i++){
        // row i -> curRow index
        for(int j = i+1 ; j < n; j++){
           double c = -1 * (matrix[j][i] / matrix[i][i]);
           addRow_Row(c,i,j,matrix,n);
        }
    }
    /*
    if(matrix[n-1][n-1] == 0 ){
        cout << "There are infinit solution" <<endl;
    }
    else{
        cout << "There is no solution" <<endl;
    }
    */
}
