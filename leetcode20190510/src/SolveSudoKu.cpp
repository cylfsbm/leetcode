#include<iostream>
#include<vector>
using namespace std;
const int row = 9;
const int col = 9;

class Solution {
public:
    /**
     * 回溯法
     * @param board [description]
     */
    void solveSudoku(vector<vector<char>>& board) {
        this->solve(board);
    }

    bool solve(vector<vector<char>>& board){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j] == '.'){
                    for(int k='1';k<='9';k++){
                        if(this->check(board, i, j, k)) {
                            board[i][j] = k;
                            if(this->solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool check(vector<vector<char>>& board, int i, int j, int k){
        for(int _i=0;_i<row;_i++){// 判断所在列是否合法
            if(_i == i) continue;
            if(board[_i][j] == k) return false;
        }
        for(int _j=0;_j<col;_j++){// 判断所在行是否合法
            if(_j == j) continue;
            if(board[i][_j] == k) return false;
        }
        for(int _i = i-i%3;_i<(i-i%3+3);_i++){
            for(int _j = j-j%3;_j<(j-j%3+3);_j++){
                if((i != _i || j != _j) && board[_i][_j] == k) {
                    return false;
                }
            }
        }
        return true;
    }

    void display(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            int counter = 0;
            for(int j=0;j<board[0].size();j++){
                if(counter == 0) {cout<<board[i][j];counter++;}
                else cout<<","<<board[i][j];
            }
            cout<<endl;
        }
    }
};

int main(){
    Solution s;
    vector<vector<char>> board = {
  {'5','3','.','.','7','.','.','.','.'},
  {'6','.','.','1','9','5','.','.','.'},
  {'.','9','8','.','.','.','.','6','.'},
  {'8','.','.','.','6','.','.','.','3'},
  {'4','.','.','8','.','3','.','.','1'},
  {'7','.','.','.','2','.','.','.','6'},
  {'.','6','.','.','.','.','2','8','.'},
  {'.','.','.','4','1','9','.','.','5'},
  {'.','.','.','.','8','.','.','7','9'}
};
    s.display(board);
    s.solveSudoku(board);
    cout<<"----------------------------------"<<endl;
    s.display(board);
    system("pause");
    return 0;
}