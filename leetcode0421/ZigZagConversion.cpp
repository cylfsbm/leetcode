/*
 * ZigZagConversion.cpp
 *
 *  Created on: 2019Äê4ÔÂ21ÈÕ
 *      Author: Administrator
 */
#include<iostream>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if(s.empty() || numRows == 1){
			return s;
		}
		string res[numRows] = { "" };
		int down = 1, topright = 0, i = 0,y = 0,count = 1;
		while (i < s.size()) {
			res[y].append(s.substr(i, 1));
			if(down == 1){
				if(count == numRows){
					down = 0;
					topright = 1;
					count = 2;
					y--;
				}else{
					count++;
					y++;
				}
			}else if(topright == 1){
				if(count == numRows){
					topright = 0;
					down = 1;
					count = 2;
					y++;
				}else{
					count++;
					y--;
				}
			}
			i++;
		}
		string result = "";
		for(int i=0;i<numRows;i++){
			result.append(res[i]);
			cout<<res[i]<<endl;
		}
		return result;
	}
};

int main() {
	Solution s;
	cout << s.convert("LEETCODEISHIRING", 2) << endl;
	return 0;
}

