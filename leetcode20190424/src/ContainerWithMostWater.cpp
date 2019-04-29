/*
 * ContainerWithMostWater.cpp
 *
 *  Created on: 2019年4月24日
 *      Author: Administrator
 */
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
	/**
	 * 双指针法(l指向最左面，r指向最右面，计算盛水量，然后选择高度小的指针移动并计算如果盛水量变大则更新最大盛水量)
	 */
    int maxArea(vector<int>& height) {
    	int l = 0,r = height.size()-1,maxHeight = 0;
    	while(l != r){
    		int h = (r-l) * min(height[l],height[r]);
    		if(h > maxHeight){
    			maxHeight = h;
    		}
    		if(height[l] < height[r]){
    			l++;
    		}else{
    			r--;
    		}
    	}
    	return maxHeight;
    }
};

int main(){

}
