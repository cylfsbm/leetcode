/*
 * PalindromeNumber.cpp
 *
 *  Created on: 2019Äê4ÔÂ23ÈÕ
 *      Author: Administrator
 */
#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
    	int X = x,num = 0;
    	if(x < 0){
    		return false;
    	}
    	while(X != 0){
    		num++;
    		X /= 10;
    	}
    	int l = 0, r = num-1;
    	while(l < r){
    		int ll = (int)(x / pow(10, r)) % 10;
    		int rr = (int)(x / pow(10, l)) % 10;
    		cout<<"ll="<<ll<<",rr="<<rr<<endl;
    		if(ll != rr){
    			return false;
    		}
    		l++;
    		r--;
    	}
    	return true;
    }
};

int main(){
	Solution s;
	cout<<s.isPalindrome(1259521)<<endl;
	return 0;
}



