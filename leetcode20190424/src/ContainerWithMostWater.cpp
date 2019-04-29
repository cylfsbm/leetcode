/*
 * ContainerWithMostWater.cpp
 *
 *  Created on: 2019��4��24��
 *      Author: Administrator
 */
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
	/**
	 * ˫ָ�뷨(lָ�������棬rָ�������棬����ʢˮ����Ȼ��ѡ��߶�С��ָ���ƶ����������ʢˮ�������������ʢˮ��)
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
