#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words){
        vector<int> res;
        if(words.empty() || s.size() < words.size() * words[0].size()) return res;
        unordered_map<string,int> dict;
        for(int i=0;i<words.size();i++){
            if(dict.find(words[i]) == dict.end()){
                dict[words[i]] = 1;
            }else{
                dict[words[i]]++;
            }
        }
        int lenOfWord = words[0].size();
       for(int strBeg = 0;strBeg < lenOfWord;strBeg++) {   // 每一个单词串开头
            unordered_map<string,int> tempDict;
            int left = strBeg, len = 0;
            for(int cur = strBeg;cur <= s.length()-lenOfWord;cur += lenOfWord) {
                string substr = s.substr(cur,lenOfWord);
                if(dict.count(substr) == 0) {   // 非法单词
                    tempDict.clear();
                    len = 0;
                    left = cur + lenOfWord;
                }else if(tempDict[substr] < dict[substr]){// 没有重复字符串
                    tempDict[substr]++;
                    len++;
                }else{// 有重复
                    string temp;
                    while((temp = s.substr(left, lenOfWord)) != substr){
                        tempDict[temp]--;
                        left += lenOfWord;
                        len--;
                    }
                    left += lenOfWord;
                }
                if(len == words.size()) {   // 此时滑窗内为所要求串
                    res.push_back(left);
                    tempDict[s.substr(left,lenOfWord)]--;
                    len--;
                    left += lenOfWord;
                }
            }
        }
        return res;
    }
};

int main(){
    // Solution s;
    // unordered_map<char,int> map;
    // for(int i=44;i<54;i++){
    //     map[(char)i] = i;
    // }
    // for(auto it:map){
    //     cout<<"key:"<<it.first<<",value:"<<it.second<<endl;
    // }
    // cout<<"-----------------------"<<endl;
    // for(auto it = map.begin();it != map.end();){
    //     if(it->first % 2 == 1){
    //         it = map.erase(it);
    //     }else{
    //         it++;
    //     }
    // }
    // for(auto it:map){
    //     cout<<"key:"<<it.first<<",value:"<<it.second<<endl;
    // }
    system("pause");
    return 0;
}