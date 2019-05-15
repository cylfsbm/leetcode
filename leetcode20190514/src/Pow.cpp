#include<iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long nn = n;
        return n >= 0 ? this->recur(x, n) : 1 / this->recur(x, -n);
    }

    double recur(double x, long n){
        if(n == 0) return 1;
        if(n % 2 == 1)
            return x * myPow(x, n-1);
        return x*x * recur(x*x, (n-2)/2);
    }
};

int main(){
    Solution s;
    cout<<s.myPow(2.0, -9)<<endl;
    system("pause");
    return 0;
}