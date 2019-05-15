#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int fac(int a){
    if(a == 0 || a == 1) return 1;
    return a*fac(a-1);
}

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v(n,-1);
        for(int i=0;i<n;i++)
            v[i] = i+1;
        string res = "";
        while(!v.empty()){
            int c = k / fac(v.size()-1);
            int r = k % fac(v.size()-1);
            res += (r == 0 ? v[c-1] : v[c])+48;
            k = (r == 0 ? fac(v.size()-1) : r);
            v.erase(v.begin() + (r == 0 ? c-1 : c));
        }
        return res;
    }
};

int main(){
    Solution s;
    int n = 5;
    for(int i=0;i<fac(n);i++){
        cout<<i+1<<":"<<s.getPermutation(n, i+1)<<endl;
    }
    system("pause");
    return 0;
}