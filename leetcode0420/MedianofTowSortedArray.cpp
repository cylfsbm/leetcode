/*
 * MedianofTowSortedArray.cpp
 *
 *  Created on: 2019年4月20日
 *      Author: Administrator
 */
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int n1 = nums1.size();
    	int n2 = nums2.size();
    	int p = (n1+n2) / 2, res = 0, count = 0;
    	if((n1+n2) % 2 == 0){// 偶数个
    		for(int i=0,j=0;count <= p;){
				int n1a = i >= n1?INT_MAX : nums1[i];
				int n2a = j >= n2?INT_MAX : nums2[j];
				printf("n1a:%d,n2a:%d\n",n1a,n2a);
				if(n1a <= n2a){
					if(count == p || count == p-1){
						res += n1a;
					}
					count++;
					i++;
				}else{
					if(count == p || count == p-1){
						res += n2a;
					}
					count++;
					j++;
				}
			}
    		return res / 2.0;
    	}else{// 奇数个
    		for(int i=0,j=0;count <= p;){
    			int n1a = i >= n1?INT_MAX : nums1[i];
    			int n2a = j >= n2?INT_MAX : nums2[j];
    			printf("n1a:%d,n2a:%d\n",n1a,n2a);
				if(n1a <= n2a){
					if(count == p){
						res += n1a;
					}
					count++;
					i++;
				}else{
					if(count == p){
						res += n2a;
					}
					count++;
					j++;
				}
			}
			return res;
    	}
    }
};

void printV(vector<int>& v){
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<",";
	}
	cout<<endl;
}

//int main(){
//	vector<int> v1;
//	vector<int> v2;
//	v1.push_back(1);
//	v1.push_back(3);
////	v2.push_back(2);
////	v2.push_back(4);
//	printV(v1);
//	printV(v2);
//	Solution s;
//	printf("%f", s.findMedianSortedArrays(v1, v2));
//	return 1;
//}



