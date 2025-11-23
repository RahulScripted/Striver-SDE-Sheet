// Given an array of N integers, count the inversion of the array




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int merge(vector<int>&nums, int low,int mid, int high){
        vector<int> temp;
        int left = low, right = mid + 1, cnt = 0;
        while(left <= mid && right <= high){
            if(nums[left] <= nums[high]){
                temp.push_back(nums[left]);
                left++;
            } else {
                temp.push_back(nums[right]);
                cnt += (mid - left + 1);
                right++;
            }
        }

        while(left <= mid){
            temp.push_back(nums[left]);
            left++;
        }

        while(right <= high){
            temp.push_back(nums[right]);
            right++;
        }

        for(int i = low; i <= high; i++){
            nums[i] = temp[i - low];
        }

        return cnt;
    }

    int mergeSort(vector<int>&nums, int low, int high){
        int cnt = 0;
        while(low >= high) return cnt;
        int mid = (low + high) / 2;
        cnt += mergeSort(nums, low, mid);
        cnt += mergeSort(nums, mid + 1, high);
        cnt += merge(nums, low, mid, high);
        return cnt;
    }
    int countInversion(vector<int>&nums, int n){
        return mergeSort(nums, 0, n - 1);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout<<"No. of inversion : "<<solution.countInversion(nums, nums.size())<<endl;
    nums = {5, 4, 3, 2, 1};
    cout<<"No. of inversion : "<<solution.countInversion(nums, nums.size())<<endl;
}