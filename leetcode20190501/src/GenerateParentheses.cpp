#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        this->generateParenthesisRecursion(n, n, "", res);
        return res;
    }

    /**
     * 递归法
     * @param left  [description]
     * @param right [description]
     * @param out   [description]
     * @param res   [description]
     */
    void generateParenthesisRecursion(int left, int right, string out, vector<string>& res){
        if(left > right){// '('个数小于')'括号个数，字符串非法
            return;
        }else if(left == 0 && right == 0){// 字符串完整且合法
            res.push_back(out);
        }else{
            if(left > 0){
                generateParenthesisRecursion(left-1, right, out+"(", res);
            }
            if(right > 0){
                generateParenthesisRecursion(left, right-1, out+")", res);
            }
        }
    }
};

void display(vector<string>& v){
    for(auto a = v.begin();a != v.end();a++){
        cout<<*a<<endl;
    }
}


int main(){
    Solution s;
    vector<string> res = s.generateParenthesis(3);
    display(res);
    system("pause");
    return 0;
}