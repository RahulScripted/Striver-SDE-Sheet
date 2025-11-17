// Given an integer array nums, find the subarray with the largest sum, and return its sum.



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadane's Algorithm
        int currentMax = 0, maximumSum = 0;
        for(int num : nums){
            currentMax = max(num, num + currentMax);
            maximumSum = max(maximumSum, currentMax);
        }
        return maximumSum;

        // DP Approach -> Tabulation T.C(O(n)) && S.C(O(n))
        // int n = nums.size();
        // vector<int>dp(nums);
        // for(int i = 1;i < n; i++){
        //     dp[i] = max(nums[i], nums[i] + dp[i - 1]);
        // }
        // return *max_element(begin(dp),end(dp));
    }
};

int main () {
    Solution solution;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<"Maximum Sum will be : "<<solution.maxSubArray(nums)<<endl;
    nums = {1};
    cout<<"Maximum Sum will be : "<<solution.maxSubArray(nums)<<endl;
    nums = {5,4,-1,7,8};
    cout<<"Maximum Sum will be : "<<solution.maxSubArray(nums)<<endl;
}