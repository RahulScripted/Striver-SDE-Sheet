// Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.



#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int longestSubarrayWithSumZero(vector<int>&nums){
        int sum = 0, maxi = 0, n = nums.size();
        unordered_map<int, int>mp;
        for(int i = 0;i < n;i++){
            sum += nums[i];

            if(sum = 0) maxi = i + 1;
            else {
                if(mp.find(sum) != mp.end()) maxi = max(maxi, i - mp[sum]);
                else mp[sum] = i;
            }
        }
        return maxi;
    }
};


int main() {
    Solution solution;

    vector<int>nums = {9, -3, 3, -1, 6, -5};
    cout<<"The length of the longest subarray with the sum of all elements equal to zero will be : "<<solution.longestSubarrayWithSumZero(nums)<<endl;

    nums = {6, -2, 2, -8, 1, 7, 4, -10};
    cout<<"The length of the longest subarray with the sum of all elements equal to zero will be : "<<solution.longestSubarrayWithSumZero(nums)<<endl;
}