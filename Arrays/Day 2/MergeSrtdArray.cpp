// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively. Merge nums1 and nums2 into a single array sorted in non-decreasing order. The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int mIdx = m - 1, nIdx = n - 1, right = (m + n) - 1;
        while(nIdx >= 0){
            if(mIdx >= 0 && nums1[mIdx] > nums2[nIdx]){
                nums1[right] = nums1[mIdx];
                mIdx--;
            }
            else {
                nums1[right] = nums2[nIdx];
                nIdx--;
            }
            right--;
        }
    }
};

void print (vector<int>nums){
    for (int i = 0; i < nums.size(); i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int main (){
    Solution solution;
    vector<int>nums1 = {1,2,3,0,0,0};
    vector<int>nums2 = {2,5,6};
    int m = 3, n = 3;
    cout<<"Before Merging : "<<endl;
    print(nums1);
    print(nums2);

    cout<<endl<<"After Merging : "<<endl;
    solution.merge(nums1,m,nums2,n);
    print(nums1);
}