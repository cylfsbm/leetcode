#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());// 升序排列用于去重
        vector<vector<int>> res;
        vector<int> v;
        this->recur(v, nums, res);
        return res;
    }

    void recur(vector<int>& v, vector<int>& nums, vector<vector<int>>& res){
        if(nums.size() == 0){
            res.push_back(vector<int>(v.begin(), v.end()));
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            v.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            this->recur(v, nums, res);
            nums.insert(nums.begin()+i, v[v.size()-1]);
            v.erase(v.begin()+v.size()-1);
        }
    }

    void display(vector<vector<int>>& v){
        for(int i=0;i<v.size();i++){
            int count = 0;
            for(int j=0;j<v[0].size();j++){
                if(count == 0){
                    cout<<v[i][j];
                    count++;
                }else{
                    cout<<"->"<<v[i][j];
                }
            }
            cout<<endl;
        }
    }
};


int main(){
    Solution s;
    vector<int> v = {1,1,2};
    vector<vector<int>> res = s.permuteUnique(v);
    s.display(res);
    system("pause");
    return 0;
}