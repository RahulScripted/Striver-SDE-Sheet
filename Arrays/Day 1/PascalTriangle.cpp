// Given an integer numRows, return the first numRows of Pascal's triangle.



#include <bit/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>pascal;
        for(int i = 0;i < numRows; i++){
            vector<int>row((i + 1), 1);
            for(int j = 1;j < i; j++){
                row[i] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
            pascal.push_back(row);
        }
        return pascal;
    }
};

void print(vector<vector<int>>&result){
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    Solution solution;
    vector<vecor<int>>result = solution.generate(5);
    print(result);
}