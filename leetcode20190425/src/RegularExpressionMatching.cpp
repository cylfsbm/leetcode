/*
 * RegularExpressionMatching.cpp
 *
 *  Created on: 2019年4月24日
 *      Author: Administrator
 */
#include<iostream>
using namespace std;

class Solution {
public:
	/**
	 * 我的方法（存在错误）
	 */
	bool isMatch(string s, string p) {
		if (s == "" && p == "") {
			return true;
		}
		int i = 0, j = 0;
		while (i < p.size()) {
			if (j == s.size()) {
				if (i == p.size() - 1 && p[i] == '*') {
					return true;
				}
				return false;
//				else{
//					if(++i >= p.size()-1){
//						return false;
//					}
//					while(i < p.size()-1){
//						if(p[i] == '*' || p[i+1] != '*'){
//							return false;
//						}
//						i += 2;
//					}
//					return true;
//				}
			}
			char temp = p[i];
			if (temp == '.') {
				j++;
				i++;
			} else if (temp == '*') {
				char pre = p[i - 1];
				if (pre == '.' || pre == s[j]) {
					j++;
				} else {
					i++;
				}
			} else {
				if (temp == s[j]) {
					i++;
					j++;
				} else {
					i++;
				}
			}
		}
		return j == s.size() ? true : false;
	}
	/**
	 * 博客园上的解法1（递归调用）
	 */
	bool isMatch2(string s, string p) {
		if (p.empty())// if p is empty , the result depends on s (s is empty return true else return false)
			return s.empty();
		if (p.size() == 1) {
			return (s.size() == 1 && (s[0] == p[0] || p[0] == '.'));// if size(p) == 1 and size(s) == s and  (s[0] == p[0] or s[0] == '.')
		}
		// size(p) > 1
		if (p[1] != '*') {
			if (s.empty())
				return false;
			return (s[0] == p[0] || p[0] == '.')
					&& isMatch2(s.substr(1), p.substr(1));
		}
		while (!s.empty() && (s[0] == p[0] || p[0] == '.')) {
			if (isMatch2(s, p.substr(2)))
				return true;
			s = s.substr(1);
		}
		return isMatch2(s, p.substr(2));
	}
};

int main() {
	Solution s;
	cout << "result:" << s.isMatch2("aaab", "a*a") << endl;
	return 0;
}

