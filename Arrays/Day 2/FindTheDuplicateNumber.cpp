// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive. There is only one repeated number in nums, return this repeated number. You must solve the problem without modifying the array nums and using only constant extra space.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Using 2  pointer 
        int slow = 0, fast = 0;
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        slow = 0;
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;

        // Using Set
        // unordered_set<int>hashSet;
        // for(int num : nums){
        //     auto result = hashSet.insert(num);
        //     if(!result.second) return num;
        // }
        // return nums.size();
    }
};

void print(vector<int> nums){
    for(int num : nums) cout<<num<<" ";
}

int main () {
    Solution solution;
    vector<int> nums = {1,3,4,2,2};
    cout<<"Duplicate number in the array : ";
    print(nums);
    cout<<solution.findDuplicate(nums)<<endl;

    nums = {3,1,3,4,2};
    cout<<"Duplicate number in the array : ";
    print(nums);
    cout<<solution.findDuplicate(nums)<<endl;

    nums = {3,3,3,3,3};
    cout<<"Duplicate number in the array : ";
    print(nums);
    cout<<solution.findDuplicate(nums)<<endl;
}