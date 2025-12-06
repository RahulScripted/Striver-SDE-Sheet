// Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to k.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNumberOfSubarrays(vector<int>&nums, int target){
        unordered_map<int, int> freq;
        freq[0] = 1;

        int count = 0, prefixXor = 0;
        for(int num : nums){
            prefixXor ^= num;
            int target = prefixXor ^ target;
            if(freq.find(target) != freq.end()) count += freq[target];
            freq[prefixXor]++;
        }
        return count;
    }
};

int main() {
    Solution solution;
    vector<int>nums = {4, 2, 2, 6, 4};
    int target = 6;
    cout<<"Total number of subarrays having bitwise XOR of all elements equal to target are : "<<solution.countNumberOfSubarrays(nums, target)<<endl;

    nums = {5, 6, 7, 8, 9};
    int target = 5;
    cout<<"Total number of subarrays having bitwise XOR of all elements equal to target are : "<<solution.countNumberOfSubarrays(nums, target)<<endl;
}