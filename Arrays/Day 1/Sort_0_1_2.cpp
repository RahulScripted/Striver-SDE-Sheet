// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue. We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively. You must solve this problem without using the library's sort function.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 1 Loop Approach
        int n = nums.size();
        int low = 0, mid = 0, high = n-1;
        while(mid <= high) {
            if(nums[mid] == 2){
                swap(nums[mid], nums[high]);
                high--;
            } else if(nums[mid] == 0){
                swap(nums[lo], nums[mid]);
                lo++;
                mid++;
            }
            else mid++;
        }

        // 2 Loop Approach
        // int n = nums.size();
        // int countZero = 0, countOne = 0, countTwo = 0;
        // for(int i=0; i<n; i++){
        //     if(nums[i] == 0) countZero++;
        //     else if(nums[i] == 1) countOne++;
        //     else countTwo++;
        // }

        // for(int i=0; i<countZero; i++){
        //     if(i < countZero) nums[i] = 0;
        //     else if(i < countZero + countOne) nums[i] = 1;
        //     else nums[i] = 2;
        // }
    }
};

void print(vector<int> nums){
    for(int i=0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main(){
    Solution solution;
    vector<int> nums = {2,0,2,1,1,0};
    cout<<"-------------Before Sorting-------------"<<endl;
    print(nums);
    solution.sortColors(nums);
    cout<<"-------------After Sorting-------------"<<endl;
    print(nums);

    nums = {2,0,1};
    cout<<"-------------Before Sorting-------------"<<endl;
    print(nums);
    solution.sortColors(nums);
    cot<<"-------------After Sorting-------------"<<endl;
    print(nums);
}