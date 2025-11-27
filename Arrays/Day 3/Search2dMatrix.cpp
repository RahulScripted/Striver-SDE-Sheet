// You are given an m x n integer matrix matrix with the following two properties:

//         1- Each row is sorted in non-decreasing order.
//         2- The first integer of each row is greater than the last integer of the previous row.

// Given an integer target, return true if target is in matrix or false otherwise. You must write a solution in O(log(m * n)) time complexity.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // Binary Search
        int rows = matrix.size(), cols = matrix[0].size();
        int left = 0, right = rows * cols - 1;
        while(left <= right){
            int mid = (left + right) / 2;
            int row = mid / cols, col = mid % cols;
            int guess = matrix[row][col];
            if(guess == target) return true;
            else if(guess < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;

        // Linear Search
        // int rows = matrix.size(), cols = matrix[0].size();
        // for(int i = 0;i < rows;i++){
        //     for(int j = 0;j < cols;j++){
        //         if(matrix[i][j] == target) return true;
        //     }
        // }
        // return false;
    }
};

int main (){
    Solution solution;
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    if(solution.searchMatrix(matrix, target)) cout<<target<<" found"<<endl;
    else cout<<target<<" not found"<<endl;

    matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    target = 13;
    if(solution.searchMatrix(matrix, target)) cout<<target<<" found"<<endl;
    else cout<<target<<" not found"<<endl;
}