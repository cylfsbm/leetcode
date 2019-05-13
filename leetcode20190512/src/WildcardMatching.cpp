#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    /**
     * 递归法 超时
     * @param  s [description]
     * @param  p [description]
     * @return   [description]
     */
    bool isMatch(string s, string p) {
        if(s.empty()) return p.empty() || p.size() == count(p.begin(), p.end(), '*');
        if(p.empty()) return false;
        if(p[0] == '*') return this->isMatch(s, p.substr(1)) || this->isMatch(s.substr(1), p) || this->isMatch(s.substr(1), p.substr(1));
        if(p[0] == '?' || s[0] == p[0]) return this->isMatch(s.substr(1), p.substr(1));
        return false;
    }

    /**
     * 动态规划法
     * @param  s [description]
     * @param  p [description]
     * @return   [description]
     */
    bool isMatch2(string s, string p){
        if(s.empty()) return p.empty() || p.size() == count(p.begin(), p.end(), '*');
        if(p.empty()) return false;
        int row = s.size(), col = p.size();
        // 二维vector dp
        vector<vector<bool>> dp(row+1, vector<bool>(col+1, false));
        // 初始化
        dp[0][0] = true;
        for(int j=1;j<=col;j++){
            if(p[j-1] == '*') dp[0][j] = true;
            else break;
        }
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                if(p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }else if(p[j-1] == '?' || p[j-1] == s[i-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[row][col];
    }
};

int main(){
    Solution s;
    // string str,p;
    // cout<<"please input the str and p:"<<endl;
    // cin>>str>>p;
    cout<<s.isMatch2("2323","22")<<endl;
    system("pause");
    return 0;
}