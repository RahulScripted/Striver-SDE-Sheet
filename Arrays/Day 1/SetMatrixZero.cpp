// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.


#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // Using constant space
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool setRows = false, setCols = false;

        for(int i = 0;i < rows;i++){
            if(matrix[i][0] == 0) setRows = true;
        }

        for(int j = 0;j < cols;j++){
            if(matrix[0][j] == 0) setCols = true;
        }

        for(int i = 1; i< rows; i++){
            for(int j = 1;j < cols; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i< rows; i++){
            for(int j = 1;j < cols; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
            }
        }


        // Using Hasmap
        // int rows = matrix.size();
        // int cols = matrix[0].size();

        // unordered_set<int> setRows;
        // unordered_set<int> setCols;

        // // Now check whether 0 or not
        // for(int i = 0;i < rows;i++){
        //     for(int j = 0;j < cols;j++){
        //         if(matrix[i][j] == 0){
        //             setRows.insert(i);
        //             setCols.insert(i);
        //         }
        //     }
        // }

        // // Now fill with 0
        // for(int i = 0;i < rows;i++){
        //     for(int j = 0;j < cols;j++){
        //         if(setRows.count(i) > 0 || setCols.count(j) > 0) matrix[i][j] = 0;
        //     }
        // }
    }
};

void printMatrix(vector<vector<int>>& matrix){
    for(int i = 0;i < matrix.size();i++){
        for(int j = 0;j < matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main (){
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    cout<<"Before Setting : "<<endl;
    printMatrix(matrix);
    Solution().setZeroes(matrix); 
    cout<<endl<<"After Setting : "<<endl;
    printMatrix(matrix);
}