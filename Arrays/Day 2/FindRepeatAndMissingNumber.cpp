// You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> missingAndRepeatatting(vector<int> &nums){
        int n = nums.size();
        long long sn = n * (n + 1) / 2;
        long long sn2 = (n * (n + 1) * (2 * n + 1)) / 6;

        long long sum = 0, sum2 = 0;
        for(int i = 0;i < n;i++){
            sum += nums[i];
            sum2 += (long long)nums[i] * (long long)nums[i];
        }

        long long val1 = sum - sn, val2 = sum2 - sn2;
        val2 /= val1;

        long long x = (val1 + val2) / 2;
        long long y = x - val1;
        return {(int)x, (int)y};
    }
};

void print(vector<int> &ans){
    cout << "Repeatatting and missing numbers are : " << ans[0] << " " << ans[1] << endl;
}

int main(){
    Solution solution;
    vector<int> nums = {3, 1, 2, 5, 3};
    vector<int> ans = solution.missingAndRepeatatting(nums);
    print(ans);
}