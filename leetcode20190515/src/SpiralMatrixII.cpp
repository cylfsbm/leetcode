#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, -1));
        int row = 0, col = 0;
        int direction[2] = {0, 1};// 前进方向
        for(int i=1;i<=n*n;i++){
            res[row][col] = i;
            if(direction[0] == 0){
                if(col+direction[1] >= n) {
                    direction[0] = 1;
                    direction[1] = 0;
                }else if(col+direction[1] < 0){
                    direction[0] = -1;
                    direction[1] = 0;
                }else{
                    if(res[row+direction[0]][col+direction[1]] != -1){
                        if(direction[1] == 1){
                            direction[0] = 1;
                            direction[1] = 0;
                        }else{
                            direction[0] = -1;
                            direction[1] = 0;
                        }
                    }
                }
            }else{// diretion[1] == 0
                if(row+direction[0] >= n) {
                    direction[0] = 0;
                    direction[1] = -1;
                }else if(row+direction[0] < 0){
                    direction[0] = 0;
                    direction[1] = 1;
                }else{
                    if(res[row+direction[0]][col+direction[1]] != -1) {
                        if(direction[0] == 1){
                            direction[0] = 0;
                            direction[1] = -1;
                        }else{
                            direction[0] = 0;
                            direction[1] = 1;
                        }
                    }
                }
            }
            row += direction[0];
            col += direction[1];
        }
        return res;
    }

    void display(vector<vector<int>>& v){
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[i].size();j++){
                if(j == 0) {cout<<v[i][j];}
                else {cout<<"->"<<v[i][j];}
            }
            cout<<endl;
        }
    }
};

int main(){
    Solution s;
    int n;
    cin>>n;
    vector<vector<int>> res = s.generateMatrix(n);
    s.display(res);
    system("pause");
    return 0;
}