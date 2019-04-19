/*
 * LongestSubstring.cpp
 *
 *  Created on: 2019Äê4ÔÂ19ÈÕ
 *      Author: Administrator
 */
#include<iostream>
#include<set>
using namespace std;

class Solution {
public:
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
};

int main() {
	Solution s = Solution();
	printf("%d", s.lengthOfLongestSubstring("pwwkew"));
	return 1;
}

