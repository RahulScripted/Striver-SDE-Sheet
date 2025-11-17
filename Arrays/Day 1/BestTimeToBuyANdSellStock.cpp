// You are given an array prices where prices[i] is the price of a given stock on the ith day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Approach - 1
        int n = prices.size();
        for(int i = (n - 1); i >= 1; i--) prices[i] = prices[i] - prices[i - 1];
        int sum = 0, maxSum = 0;
        for(int i = 1;i < n;i++){
            sum += prices[i];
            maxSum = max(maxSum, sum);
            sum = max(sum, 0);
        }
        return maxSum;

        // Approach - 2
        // int sell = 0, hold = INT_MIN;
        // for(int price : prices){
        //     sell = max(sell,hold + price);
        //     hold = max(hold, -price);
        // }
        // return sell;
    }
};

int main (){
    Solution solution;

    // 1st
    vector<int>prices = {7,1,5,3,6,4};
    cout<<"Max Profit we can gain : "<<solution.maxProfit(prices)<<endl;

    // 2nd
    prices = {7,6,4,3,1};
    cout<<"Max Profit we can gain : "<<solution.maxProfit(prices)<<endl;
}