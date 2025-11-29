// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target. You may assume that each input would have exactly one solution, and you may not use the same element twice. You can return the answer in any order.



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Optimized solution
        int n = nums.size();
        unordered_map<int, int>mp;
        for(int i = 0;i < n;i++){
            int num = nums[i];
            if(mp.find(target - num) != mp.end()) return {i, mp[target - num]};
            mp[num] = i;
        }
        return {};

        // Brute-force solution
        // int n = nums.size();
        // for(int i = 0;i < n;i++){
        //     for(int j = (i + 1);j < n;j++){
        //         if((nums[i] + nums[j]) == target) return {i,j};
        //     }
        // }
        // return {};
    }
};

int main (){
    Solution solution;
    vector<int>nums = {2,7,11,15};
    int target = 9;
    vector<int>ans = solution.twoSum(nums, target);
    cout<<"Indexs are : "<<ans[0]<<" and "<<ans[1]<<endl;
}