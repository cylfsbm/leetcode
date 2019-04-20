/*
 * LongestPalindromicSubstring.cpp
 *
 *  Created on: 2019年4月20日
 *      Author: Administrator
 */
#include<iostream>
using namespace std;

class Solution {
public:
	/**
	 * 我的解法（时间复杂度太高）
	 */
    string longestPalindrome(string s) {
    	string res = "";
    	int max = 0;
    	for(int i=0;i<s.size();i++){
    		for(int j=i;j<s.size();j++){
    			int result = this->isPalindromicSubstring(s.substr(i, j-i+1));
    			if(result > 0 && result > max){
    				max = result;
    				res = s.substr(i, j-i+1);
    			}
    		}
    	}
    	return res;
    }

    int isPalindromicSubstring(string s){
    	int length = s.size();
    	for(int i=0;i<length/2;i++){
    		char a = s[i];
    		char b = s[length-i-1];
    		if(a != b)
    			return -1;
    	}
    	return length;
    }

    /**
     * 博客园上面的快速解法1
     */
    string longestPalindrome2(string s) {
		if (s.size() < 2) return s;
		int n = s.size(), maxLen = 0, start = 0;
		for (int i = 0; i < n - 1; ++i) {
			searchPalindrome(s, i, i, start, maxLen);
			searchPalindrome(s, i, i + 1, start, maxLen);
		}
		return s.substr(start, maxLen);
	}
	void searchPalindrome(string s, int left, int right, int& start, int& maxLen) {
		while (left >= 0 && right < s.size() && s[left] == s[right]) {
			--left; ++right;
		}
		if (maxLen < right - left - 1) {
			start = left + 1;
			maxLen = right - left - 1;
		}
	}

	/**
	 * 动态规划法
	 */
	string longestPalindrome3(string s){
		if(s.empty()){
			return "";
		}
		int length = s.size();
		int m[length][length] = {0},left = 0,right = 0,len = 0;
		for(int i=0;i<length;i++){
			m[i][i] = 1;
			for(int j=0;j<i;j++){
				m[j][i] = (s[i] == s[j] && (i-j < 2 || m[j+1][i-1]));
				if (m[j][i] && len < i - j + 1) {
					len = i - j + 1;
					left = j;
					right = i;
				}
			}
		}
		return s.substr(left, right-left+1);
	}
};

int main(){
	Solution s;
	cout<<s.longestPalindrome3("a");
	return 0;
}



