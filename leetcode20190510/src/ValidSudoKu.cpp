// 有效数独
#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<char> s;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(i % 3 == 0 && j % 3 == 0){// 遍历九宫格
                    for(int m=i;m<i+3;m++){
                        for(int n=j;n<j+3;n++){
                            char temp = board[m][n];
                            if(temp != '.'){
                                if(s.count(temp) == 1) return false;
                                s.insert(temp);
                            }
                        }
                    }
                    s.clear();
                }
                if(i == 0){// 遍历每列
                    for(int m=0;m<board.size();m++){
                        char temp = board[m][j];
                        if(temp != '.'){
                            if(s.count(temp) == 1) return false;
                            s.insert(temp);
                        }
                    }
                    s.clear();
                }
                if(j == 0){// 遍历每行
                    for(int n=0;n<board[0].size();n++){
                        char temp = board[i][n];
                        if(temp != '.'){
                            if(s.count(temp) == 1) return false;
                            s.insert(temp);
                        }
                    }
                    s.clear();
                }
            }
        }
        return true;
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
    cout<<s.isValidSudoku(board)<<endl;
    system("pause");
    return 0;
}