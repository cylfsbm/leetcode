/*
 * String2Integer.cpp
 *
 *  Created on: 2019年4月23日
 *      Author: Administrator
 */
#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		bool firstNoSpaceAppear = false;
		int i = 0;
		string res = "";
		while (i < str.size()) {
			char c = str[i];
			if (firstNoSpaceAppear) { // 第一个非空格字符已出现
				if (c >= '0' && c <= '9') { // 数字字符
					res += c;
					i++;
				} else {
					break;
				}
			} else { // 第一个非空格字符未出现
				if (c == ' ') {
					i++;
					continue;
				} else {
					if (c == '-' || c == '+' || (c >= '0' && c <= '9')) {
						res += c;
						firstNoSpaceAppear = true;
						i++;
					} else {
						return 0;
					}
				}
			}
		}
		double result = 0;
		int flag = 1;
		if (res[0] == '-') {
			flag = 0;
			res = res.substr(1, res.size() - 1);
		}
		if (res[0] == '+') {
			res = res.substr(1, res.size() - 1);
		}
		for (int i = 0; i < res.size(); i++) {
			result += (res[i] - 48) * pow(10, res.size() - i - 1);
			if (flag == 1 && result >= INT_MAX) {
				return INT_MAX;
			}else if(flag == 0 && result*(-1) <= INT_MIN){
				return INT_MIN;
			}
		}
		return (int) (flag == 1 ? result : result * (-1));
	}
};

//int main() {
//	Solution s;
//	cout << s.myAtoi("-2147483647") << endl;
//	return 0;
//}

