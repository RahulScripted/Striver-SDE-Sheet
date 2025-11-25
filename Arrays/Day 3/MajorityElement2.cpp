// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Boyer-Moore Majority Vote algorithm  -> Time Complexity: O(n), Space Complexity: O(1)
        int majority1 = 0, majority2 = 0, count1 = 0, count2 = 0, n = nums.size();
        for(int num : nums){
            if(num == majority1) count1++;
            else if(num == majority2) count2++;
            else if(count1 == 0){
                majority1 = num;
                count1++;
            } else if (count2 == 0){
                majority2 = num;
                count2++;
            } else{
                count1--;
                count2--;
            }
        }

        count1 = 0, count2 = 0;
        for(int num : nums){
            if(num == majority1) count1++;
            else if(num == majority2) count2++;
        }

        vector<int>res;
        if(count1 > n/3) res.push_back(majority1);
        else if(count2 > n/3) res.push_back(majority2);
        return res;

        // Using Map -> Time Complexity: O(n), Space Complexity: O(n)
        // int n = nums.size();
        // unordered_map<int, int>mp;
        // vector<int>res;
        // for (auto i: nums) mp[i]++;
        
        // for (auto i: mp) {
        //     if (i.second > n/3) res.push_back(i.first);
        // }
        // return res;
    }
    
};

void print(vector<int>ans) {
    for (auto i: ans) cout<<i<<" ";
    cout<<endl;
}

int main () {
    Solution solution;
    vector<int>nums = {1, 2};
    vector<int>ans = solution.majorityElement(nums);
    cout<<"Majority elements are : ";
    print(ans);

    nums = {3, 2, 3};
    ans = solution.majorityElement(nums);
    cout<<"Majority elements are : ";
    print(ans);
}