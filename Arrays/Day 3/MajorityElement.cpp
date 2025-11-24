// Given an array nums of size n, return the majority element. The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.




#includ <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        // Optimal Approach
        int res = 0, majority = 0;
        for(int num : nums){
            if(majority == 0) res = num;
            majority += n == res ? 1 : -1;
            return res;
        }
        
        // Sorting
        // int n = nums.size();
        // sort(nums.begin(), nums.end());
        // return nums[n/2];
    }
};

int main (){
    Solution solution;
    vector<int> nums = {3,2,3};
    cout<<"Majority Element is : "<<solution.majorityElement(nums)<<endl;

    nums = {2,2,1,1,1,2,2};
    cout<<"Majority Element is : "<<solution.majorityElement(nums)<<endl;
}