#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.empty() || s.empty() || s.length() < words.size()*words[0].length()) return res;   // 一定不行的情况

        int lenOfWord = words[0].length();    // 记录单词的长度
        unordered_map<string,int> dict; // 存最初的单词以及出现次数

        for(int i = 0;i < words.size();i++) {   // 初始化最初的dict
            if(dict.find(words[i]) == dict.end()) {
                dict.insert(make_pair(words[i],1));
            } else {
                dict[words[i]]++;
            }
        }
        // 以单词位单位进行遍历
        // strBeg: 每个单词串的开头
        for(int strBeg = 0;strBeg < lenOfWord;strBeg++) {   // 每一个单词串开头
            unordered_map<string,int> tempDict;
            int left = strBeg, len = 0;
            for(int cur = strBeg;cur <= s.length()-lenOfWord;cur += lenOfWord) {
                string substr = s.substr(cur,lenOfWord);
                if(dict.count(substr) == 0) {   // 非法单词
                    tempDict.clear();
                    len = 0;
                    left = cur + lenOfWord;
                } else {
                    if(tempDict[substr] < dict[substr]) { // 没有重复
                        tempDict[substr]++;
                        len++;
                    } else { // 有重复
                        string temp;
                        while((temp = s.substr(left,lenOfWord)) != substr) {
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
        }
        return res;
    }
};