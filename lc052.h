#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int num = 0;


    int totalNQueens(int n) {
        vector<string> chessboard(n, string(n, '.'));
        backtrack(chessboard, 0);
        return num;
    }

    void backtrack(vector<string> &chessboard, int row) {
        // 触发结束条件
        if (row == chessboard.size()) {
            num++;
            return;
        }

        for (int col = 0; col < chessboard.size(); ++col) {
            //排除不合法选择
            if (!isValid(chessboard, row, col)) {
                continue;
            }

            //做选择
            chessboard[row][col] = 'Q';
            //进入下一层决策树
            backtrack(chessboard, row + 1);
            //撤销选择
            chessboard[row][col] = '.';
        }
    }

    //因为皇后是一排一排放的，所以下方是没有皇后的，不需要检查
    //只需要检查正上方，左上方，右上方
    bool isValid(vector<string> &chessboard, int row, int col) {
        int n = chessboard.size();
        //检查同一列
        for (int i = 0; i < row; ++i) {
            if (chessboard[i][col] == 'Q') {
                return false;
            }
        }
        //检查左上方
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        //检查右上方
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};