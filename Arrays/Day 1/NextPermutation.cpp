// A permutation of an array of integers is an arrangement of its members into a sequence or linear order.For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), idx = -1;
        for(int i = (n - 2);i >= 0;i--){
            if(nums[i] < nums[i + 1]){
                idx = i;
                break;
            }
        }

        if(idx == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i = (n - 1); i > idx;i--){
            if(nums[i] > nums[idx]){
                swap(nums[i], nums[idx]);
                break;
            }
        }

        reverse(nums.begin() + idx + 1, nums.end());
    }
};

void print (vector<int> &nums){
    int n = nums.size();
    for(int i = 0;i < n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int main (){
    Solution solution;
    vector<int>nums = {1,2,3};
    cout<<"Current Array : ";
    print(nums);
    solution.nextPermutation(nums);
    cout<<"Next Permutation Array : ";
    print(nums);
    
    nums = {3, 2, 1};
    cout<<"Current Array : ";
    print(nums);
    solution.nextPermutation(nums);
    cout<<"Next Permutation Array : ";
    print(nums);

    nums = {1, 1, 5};
    cout<<"Current Array : ";
    print(nums);
    solution.nextPermutation(nums);
    cout<<"Next Permutation Array : ";
    print(nums);
}