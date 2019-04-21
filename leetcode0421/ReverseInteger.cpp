/*
 * ReverseInteger.cpp
 *
 *  Created on: 2019年4月21日
 *      Author: Administrator
 */
#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
    	long result = 0;
    	int flag = 1;// 正数
    	if(x < 0){
    		flag = 0;// 负数
    	}
    	long lx = abs((long)x);
    	string x_str = to_string(lx);
    	int l=0,r=x_str.size()-1;
    	while(l < r){
			char temp = x_str[l];
			x_str[l] = x_str[r];
			x_str[r] = temp;
			result += (((int)x_str[l]-48) * pow(10,r) + ((int)x_str[r]-48) * pow(10,l));
			if(result > INT_MAX || result < INT_MIN){
				return 0;
			}
			l++;
			r--;
    	}
    	if(l == r){
			result += ((int)x_str[l]-48) * pow(10,l);
    		if(result > INT_MAX || result < INT_MIN){
				return 0;
			}
    	}
    	return flag == 1?(int)result:(int)result*(-1);
    }
};

int main(){
	Solution s;
	cout<<s.reverse(-48)<<endl;
	return 0;
}



