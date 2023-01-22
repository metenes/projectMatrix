#include "Calix.h"

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

    Calix::Calix(){
        // Matrix
    }

    Calix::Calix(double** matrix){
        // TODO
    }

    void Calix::switchRows(int row_int, int row_new , double** matrix){
        double* temp = *(matrix + row_int);
        *(matrix + row_int) = *(matrix + row_new);
        *(matrix + row_new) = temp;
    }

    void Calix::addRow_Row(double c ,int row_int, int row_new , double** matrix, int n){
        for(int i = 0; i < n; i++){
            *(*(matrix + row_new)+i) = c*( *(*(matrix + row_int)+i) ) + ( *(*(matrix + row_new)+i) );
            if(*(*(matrix + row_new)+i) == -0){
                *(*(matrix + row_new)+i) = 0;
            }
        }

    }


    void Calix::multRow(double c ,int row, double** matrix, int n){
        for(int i = 0; i < n; i++){
            *(*(matrix + row)+i) = c *( *(*(matrix + row)+i) );
            if(*(*(matrix + row)+i) == -0){
                *(*(matrix + row)+i) = 0;
            }
        }
    }

    // Display Square Matrix
    void Calix::displayMatrix(double** matrix, int n){
        for(int i = 0; i < n; i++){
            cout<<"| ";
            for(int j = 0; j < n-1; j++){
                cout << matrix[i][j] << " ";
            }
            cout << matrix[i][n-1] << " |" <<endl;
        }
    }

    // Display non-Square Matrix
    void Calix::displayMatrix(double** matrix, int n, int m){
        for(int i = 0; i < n; i++){
            cout<<"| ";
            for(int j = 0; j < m-1; j++){
                cout << matrix[i][j] << " ";
            }
            cout << matrix[i][m-1] << " |" <<endl;
        }
    }

    double** Calix::matrixSum(){
        int row, col;
        cout << "- Matrix sum is valid for matrix(s) have same number of row and column -" << endl;
        cout << "Enter the number of rows and columns" << endl;
        cin >> row >> col;

        // Result matrix
        double** matrixR = new double*[row];

        for(int i = 0; i < row; i++ ){
            matrixR[i] = new double[col];
            for(int j = 0; j < col; j++){
                matrixR[i][j] = 0;
            }
        }


        // Matrix list
        vector < double** > matrixList;
        for(int k = 0; k < 2; k++ ){
            double** curMatrix = new double* [row];
            cout << "Enter Matrix number " << k + 1 << endl;
            for(int i = 0; i < row; i++ ){
                curMatrix[i] = new double[col];
                for(int j = 0; j < col; j++){
                    double m;
                    cin >> m;
                    curMatrix[i][j] = m;
                }
            }
            matrixList.push_back(curMatrix);
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col ; j++){
                for(int k = 0; k < matrixList.size(); k++ ){
                    matrixR[i][j] += matrixList.at(k)[i][j];
                }
            }
        }

        for(int k = 0; k < matrixList.size(); k++ ){
            delete [] matrixList.at(k);
        }

        return matrixR;
    }


    double** Calix::matrixMult(){
        cout << "First Matrix's column number must be same with second Matrix's row number" << endl;

        // Result Matrix
        int rowR , colR;

        double** matrix1;
        double** matrix2;
        // Matrix list
        vector < double** > matrixList = { matrix1 , matrix2};

        double** matrixR;

        // Check for Matrix constrains
        bool check = true;
        int checkS;
        for(int k = 0; k < 2; k++){
          cout << "Enter the number of rows and columns for Matrix #" << k+1 << endl;
          int row, col;
          cin >> row >> col;
            if(k == 0){
                rowR = row;
                checkS = col;
            }
            else{
                if(checkS != row){
                    cout << "First Matrix's column number must be same with second Matrix's row number" << endl;
                    check = false;
                    break;
                }
                else{
                    colR = col;
                }
            }

            matrixList[k] = new double*[row];
            double** curMatrix = matrixList[k];
            for(int i = 0; i < row; i++ ){
                cout << "Enter the numbers Matrix #" << k+1 << endl;
                curMatrix[i] = new double[col];
                for(int j = 0; j < col; j++){
                    double m;
                    cin >> m;
                    curMatrix[i][j] = m;
                }
            }
        }

        if(check){
         // Result matrix
            //displayMatrix();
            matrixR = new double*[rowR];

        }



    }

    void Calix::makeEchollon(double** matrix, double** matrixRev, int n){
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
        cout<<"Matrix"<<endl;
        displayMatrix(matrix,n);

        cout<<"Reverse Matrix"<<endl;
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

    void Calix::matRev(){

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
                bool check = true;
                if(matrix[j][i] != 0){
                    switchRows(i,j,matrix);
                    switchRows(i,j,matrixRev);
                    check = false;
                    break;
                }
                if(check){
                    cout<<" one of the columns has of all its rows filled with 0 "<<endl;
                    cout<<" extra varaible error "<<endl;
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
