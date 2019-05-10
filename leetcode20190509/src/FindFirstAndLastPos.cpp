#include<iostream>
#include<vector>
// #include<cmath>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1,-1};
        int beg = 0, end = nums.size()-1;
        int begFlag = 0, endFlag = 0;
        while(beg <= end && (begFlag + endFlag) != 2){
            if(nums[beg] == target && begFlag == 0){
                begFlag++;
                res[0] = beg;
            }
            if(nums[end] == target && endFlag == 0){
                endFlag++;
                res[1] = end;
            }
            if(begFlag == 0){
                beg++;
            }
            if(endFlag == 0){
                end--;
            }
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<int> v;
    v.push_back(5);
    v.push_back(7);
    v.push_back(7);
    v.push_back(8);
    v.push_back(8);
    v.push_back(8);
    v.push_back(10);
    vector<int> res = s.searchRange(v, 8);
    for(auto i:res){
        cout<<i<<endl;
    }
    system("pause");
    return 0;
}