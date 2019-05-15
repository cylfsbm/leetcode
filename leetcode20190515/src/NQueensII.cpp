#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

/**
 * 回溯法（速度较慢）
 */
class Solution {
public:
    int totalNQueens(int n) {
        int counter = 0;
        char** board = new char*[n];
        for(int i=0;i<n;i++)
            board[i] = new char[n]{'.'};
        this->recur(board, counter, n, n, 0, 0);
        return counter;
    }

    void recur(char** board, int& counter, int qnum, int n, int _i, int _j){
        if(qnum == 0) {
            counter++;
            return;
        }
        for(int i=_i;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == _i && j < _j) continue;
                if(board[i][j] != 'Q' && this->isValid(board, i, j, n)) {
                    board[i][j] = 'Q';
                    this->recur(board, counter, qnum-1, n, i, j);
                    board[i][j] = '.';
                }
            }
        }
    }

    bool isValid(char** board, int i, int j, int n){
        for(int _j=0;_j<n;_j++)
            if(board[i][_j] == 'Q') return false;
        for(int _i=0;_i<n;_i++)
            if(board[_i][j] == 'Q') return false;
        for(int _i=0;_i<n;_i++){
            for(int _j=0;_j<n;_j++){
                if(abs(i-_i) == abs(j-_j) && board[_i][_j] == 'Q') return false;
            }
        }
        return true;
    }
};
/**
 * 回溯法（速度更快）
 */
class Solution2 {
private:
    int counter = 0;
public:
    int totalNQueens(int n) {
        int* board = new int[n]{0};
        recur(board, 0, n);
        return counter;
    }

    void recur(int* board, int row, int n){
        if(row >= n) {counter++;return;}
        for(int i=0;i<n;i++){
            board[row] = i;
            if(this->isValid(board, row)) {
                recur(board, row+1, n);
            }
        }
    }

    bool isValid(int* board, int row){
        for(int i=0;i<row;i++){
            if(board[i] == board[row] || abs(i-row) == abs(board[i]-board[row])) return false;
        }
        return true;
    }
};
int main(){
    Solution s;
    int counter = s.totalNQueens(9);
    cout<<counter<<endl;
    system("pause");
    return 0;
}