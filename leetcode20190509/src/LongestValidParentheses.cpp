#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    /*int longestValidParentheses(string s) {
        if(s.size() < 2) return 0;
        int pos = 0;
        while(pos < s.size() && s[pos] == ')') pos++;// 求得此时counter为第一个(字符的位置
        int max = 0, leftNum = 0, rightNum = 0, cur = pos;
        while(pos != s.size()){
            cur = pos;
            leftNum = 0, rightNum = 0;
            if(s.size() - cur <= max) break;
            while(cur != s.size()){
                if(s[cur] == '(') leftNum++;
                else rightNum++;
                if(rightNum > leftNum) {
                    max = max<leftNum*2?leftNum*2:max;
                    leftNum = 0, rightNum = 0;
                    break;
                }
                cur++;
            }
            if(cur == s.size()) max = max<rightNum*2?rightNum*2:max;
            do {pos++;} while(pos < s.size() && s[pos] == ')');
        }
        return max;
    }*/
    /**
     * 动态规划法
     * @param  s [description]
     * @return   [description]
     */
    int longestValidParentheses(string s){
        if(s.size() < 2) return 0;
        int* d = new int[s.size()]{0};
        int max = 0, len = s.size();
        for(int index = len-2; index >= 0; index--){
            int symIndex = index+1+d[index+1];
            if('(' == s[index] && symIndex < len && ')' == s[symIndex]){
                d[index] = d[index+1]+2;
                if(symIndex+1 < len){
                    d[index] += d[symIndex+1];
                }
            }
            max = max > d[index]?max:d[index];
        }
        delete[] d;
        return max;
    }
};

int main(){
    Solution s;
    string str;
    cin>>str;
    cout<<s.longestValidParentheses(str)<<endl;
    system("pause");
    return 0;
}