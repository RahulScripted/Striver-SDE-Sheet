// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>numSet(nums.begin(), nums.end());
        int longestStreak = 0;
        for(int num : numSet){
            if(numSet.find(num - 1) == numSet.end()){
                int length = 1;
                while(numSet.find(num + length) != numSet.end()) length++;
                longestStreak = max(longestStreak, length);
            }
        }
        return longestStreak;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << "Longest consecutive sequence length: " << sol.longestConsecutive(nums) << endl;

    nums = {0,3,7,2,5,8,4,6,0,1};
    cout << "Longest consecutive sequence length: " << sol.longestConsecutive(nums) << endl;
}