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

    Calix(){
        // Matrix
    }

    Calix(double** matrix){
        // TODO
    }

    void switchRows(int row_int, int row_new , double** matrix){
        double* temp = *(matrix + row_int);
        *(matrix + row_int) = *(matrix + row_new);
        *(matrix + row_new) = temp;
    }

    void addRow_Row(double c ,int row_int, int row_new , double** matrix, int n){
        for(int i = 0; i < n; i++){
            *(*(matrix + row_new)+i) = c*( *(*(matrix + row_int)+i) ) + ( *(*(matrix + row_new)+i) );
            if(*(*(matrix + row_new)+i) == -0){
                *(*(matrix + row_new)+i) = 0;
            }
        }

    }


    void multRow(double c ,int row, double** matrix, int n){
        for(int i = 0; i < n; i++){
            *(*(matrix + row)+i) = c *( *(*(matrix + row)+i) );
            if(*(*(matrix + row)+i) == -0){
                *(*(matrix + row)+i) = 0;
            }
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

    void makeEchollon(double** matrix, double** matrixRev, int n){
        if(matrix[0][0] == 0){
            cout << "Can not make Echollon matrix due to first element is 0" << endl;
            return;
        }
        else if(matrix[0][0] != 1 ){
            multRow(1/matrix[0][0], 0, matrix, n);
        }

        // Lower triangle form
        for(int i = 0 ; i < n-1; i++){
            // row i -> curRow index
            for(int j = i+1 ; j < n; j++){
                double c = -1 * (matrix[j][i] / matrix[i][i]);
                addRow_Row(c,i,j,matrix,n);
                double div = 1/matrix[j][j];
                multRow(div,j,matrix,n);
                // Rev Matrix
                addRow_Row(c,i,j,matrixRev,n);
                multRow(div,j,matrixRev,n);
            }
        }
        cout<<"matix"<<endl;
        displayMatrix(matrix,n);

        cout<<"rev matrix"<<endl;
        displayMatrix(matrixRev,n);


        // Upper triangle form
        for(int i = n-1 ; i >= 0; i--){
            // row i -> curRow index
            for(int j = i-1 ; j >= 0; j--){
                double c = -1 * (matrix[j][i] / matrix[i][i]);
                addRow_Row(c,i,j,matrix,n);
                double div = 1/matrix[j][j];
                multRow(div,j,matrix,n);
                // Rev Matrix
                addRow_Row(c,i,j,matrixRev,n);
                multRow(div,j,matrixRev,n);
            }
        }

        // Pivot are visible

        if(matrix[n-1][n-1] == 0 && matrixRev[n-1][0] == 0){
            cout << "There are infinite solution for at least 1 value values" <<endl;
        }
        else if (matrix[n-1][n-1] == 0 && matrixRev[n-1][0] != 0){
            cout << "There is no solution" <<endl;
        }
        else if (matrix[n-1][n-1] != 0 ){
            cout << "There is single solution" <<endl;
        }
    }

    void matRev(){

        cout << "Enter the number of rows and columns \n- only some of square matrix can be reversed -" << endl;
        int n;
        cin >> n;

        double** matrix = new double*[n];

        for(int i = 0; i < n; i++ ){
            matrix[i] = new double[n];
            for(int j = 0; j < n; j++){
                double m;
                cin >> m;
                matrix[i][j] = m;
            }
        }

    // Unit Matrix
        double** matrixRev = new double*[n];

        for(int i = 0; i < n; i++ ){
            matrixRev[i] = new double[n];
            for(int j = 0; j < n; j++){
                if(j == i){
                    matrixRev[i][j] = 1;
                }
                else{
                    matrixRev[i][j] = 0;
                }
            }
        }

        for(int i = 0; i < n-1; i++){
            if(matrix[i][i] == 0 ){
            for(int j = i + 1; j < n; j++){
                if(matrix[j][i] != 0){
                    switchRows(i,j,matrix);
                    break;
                }
            }
            }
        }

        displayMatrix(matrix,n);
        cout<<endl;
        makeEchollon(matrix, matrixRev, n);
        cout<<endl;
        cout<<"Current Matrix in Unit Form"<<endl;
        displayMatrix(matrix,n);
        cout<<endl;
        cout<<"Reversed Matrix "<<endl;
        displayMatrix(matrixRev,n);
        cout<<endl;

        delete [] matrixRev;
        delete [] matrix;
    }

};


int main(){
    Calix test;
    test.matRev();
}


