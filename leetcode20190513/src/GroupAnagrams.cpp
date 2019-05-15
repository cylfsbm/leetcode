#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
    /**
     * 我的解法，正确但是最后一个测试用例超时
     */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> map;
        for(int i=0;i<strs.size();i++){
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            if(map.find(temp) == map.end()){
                map[temp] = vector<string>(1, strs[i]);
            }else{
                map[temp].push_back(strs[i]);
            }
        }
        for(auto it = map.begin();it != map.end();it++)
            res.push_back(it->second);
        return res;
    }


    void display(vector<vector<string>>& v){
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                if(j == 0){
                    cout<<v[i][j];
                }else{
                    cout<<"->"<<v[i][j];
                }
            }
            cout<<endl;
        }
    }
};

int main(){
    Solution s;
    vector<string> v = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = s.groupAnagrams(v);
    s.display(res);
    system("pause");
    return 0;
}