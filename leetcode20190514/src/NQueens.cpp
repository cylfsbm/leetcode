#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class Solution {
public:
    /**
     * 回溯法(运行速度较慢，节省空间)
     */
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));// 棋盘
        this->recur(res, board, n, n, 0, 0);
        return res;
    }

    void recur(vector<vector<string>>& res, vector<string>& board, int n, int qnum, int _i, int _j){
        if(qnum == 0){
            res.push_back(vector<string>(board.begin(), board.end()));
            return;
        }
        for(int i=_i;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == _i && j < _j) continue;
                if(board[i][j] == '.' && this->isValid(board, i, j, n)){
                    board[i][j] = 'Q';
                    this->recur(res, board, n, qnum-1, i, j);
                    board[i][j] = '.';
                }
            }
        }
    }

    bool isValid(vector<string>& board, int i, int j, int n){
        for(int _j=0;_j<n;_j++){
            if(board[i][_j] == 'Q') return false;
        }
        for(int _i=0;_i<n;_i++){
            if(board[_i][j] == 'Q') return false;
        }
        for(int _i=0;_i<n;_i++){
            for(int _j=0;_j<n;_j++) if(abs(_i-i) == abs(_j-j) && board[_i][_j] == 'Q') return false;
        }
        return true;
    }
};

int main(){
    Solution s;
    vector<vector<string>> res = s.solveNQueens(9);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<endl;
        }
        cout<<"----------------"<<endl;
    }
    cout<<res.size()<<endl;
    system("pause");
    return 0;
}