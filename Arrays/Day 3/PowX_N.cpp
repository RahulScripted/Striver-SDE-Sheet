// Implement pow(x, n), which calculates x raised to the power n (i.e., xn).




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        return findMyPow(x, static_cast<long>(n));
    }

private:
    double findMyPow(double x, long n){
        if(n == 0) return 1;
        else if(n < 0) return 1 / findMyPow(x, -n);
        else if(n % 2 == 1) return x * findMyPow(x * x, (n - 1) / 2);
        else return findMyPow(x * x, n / 2);
    }
};

int main (){
    Solution solution;
    double x = 2.00000;
    int n = 10;
    cout<<x<<" to the power "<<n<<" is "<<solution.myPow(x, n)<<endl;

    x = 2.00000;
    n = -2;
    cout<<x<<" to the power "<<n<<" is "<<solution.myPow(x, n)<<endl;
}