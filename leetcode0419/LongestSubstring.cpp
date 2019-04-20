/*
 * LongestSubstring.cpp
 *
 *  Created on: 2019年4月19日
 *      Author: Administrator
 */
#include<iostream>
#include<set>
using namespace std;

class Solution {
public:
	/**
	 * 我的解法
	 */
	int lengthOfLongestSubstring(string s) {
		int count = 0, max = 0;
		for (int p = 0; p < s.length(); p++) {
			if (max > (s.length() - p))
				break;
			set<char> ss;
			int i;
			for (i = p; i < s.length(); i++) {
				if (ss.count(s.at(i)) == 1) {
					if (count > max) {
						max = count;
					}
					count = 0;
					break;
				} else {
					ss.insert(s.at(i));
					count++;
				}
			}
			if (i == s.length()) {
				if (count > max) {
					max = count;
				}
				count = 0;
			}
		}
		return max;
	}

	/**
	 * 博客园上的快速解法
	 */
	int lengthOfLongestSubstring2(string s){
		int left = 0, res = 0, m[256] = {0};
		for(int i=0;i<s.size();i++){
			if(m[s[i]] == 0 || m[s[i]] < left){
				res = max(res, i-left+1);
			}else{
				left = m[s[i]];
			}
			m[s[i]] = i + 1;
		}
		return res;
	}
};

int main() {
	Solution s = Solution();
	printf("%d", s.lengthOfLongestSubstring("pwwkew"));
	return 1;
}

