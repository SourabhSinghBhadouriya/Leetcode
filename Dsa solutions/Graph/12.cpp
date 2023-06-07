#include<bits/stdc++.h>
using namespace std;

//73. Set Matrix Zeroes

void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<int> rowNum(row, 0);
        vector<int> colNum(col, 0);
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(matrix[i][j] == 0){
                    rowNum[i] = 1;
                    colNum[j] = 1;
                }
            }
        }

        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(  rowNum[i] == 1||
                    colNum[j] == 1){
                    matrix[i][j] = 0;
                 
                }
            }
        }
    }