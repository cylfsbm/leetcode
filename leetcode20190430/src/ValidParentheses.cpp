#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(int i=0;i<s.size();i++){
            char c = s[i];
            if(stack.size() != 0 && this->isMatch(stack.top(), c)){
                // cout<<stack.top()<<" match "<<c<<endl;
                stack.pop();
            }else{
                // cout<<"not match"<<endl;
                stack.push(c);
            }
        }
        return stack.empty();
    }

    bool isMatch(char c1, char c2){
        if((c1 == '(' && c2 == ')') || (c1 =='{' && c2 == '}') || (c1 == '[' && c2 == ']')) {
            return true;
        }
        return false;
    }
};

int main(){
    Solution sol;
    string s;
    cin>>s;
    cout<<s<<":"<<sol.isValid(s)<<endl;
    system("pause");
    return 0;
}