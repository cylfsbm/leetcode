#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int pos = 0;
        while(this->charIsCommon(strs, pos++));
        // cout<<pos<<endl;
        return strs.size() == 0 ? "" : strs[0].substr(0,pos-1);
    }

    bool charIsCommon(vector<string>& strs, int pos){
        set<char> set;
        for(int i=0;i<strs.size();i++){
            if(strs[i].size() <= pos){
                return false;
            }
            set.insert(strs[i][pos]);
        }
        return set.size() == 1;
    }
};

int main(){
    Solution s;
    vector<string> v;
    // v.push_back("flower");
    // v.push_back("dog");
    // v.push_back("cat");
    cout<<"res:"<<s.longestCommonPrefix(v)<<endl;
    system("pause");
    return 0;
}