#include<iostream>
#include<climits>
using namespace std;

class Solution {
public:
    /**
     * 动态规划法
     * @param  nums [description]
     * @return      [description]
     */
    int jump(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size, INT_MAX);
        dp[0] = 0;
        int far = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] + i <= far) continue;
            far = nums[i] + i;
            for(int j=0;j<=nums[i];j++){
                dp[i+j] = dp[i] + 1 <= dp[i+j] ? dp[i] + 1 : dp[i+j];
                if(i+j == size-1) return dp[size-1];
            }
        }
        return dp[size-1];
    }
};

int main(){
    return 0;
}