#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        row_ = matrix.size();
        col_ = matrix[0].size();
        vector<bool> visited(row_ *col_);
        matrix_ = matrix;
        int longest = 1;
        for (int i = 0; i < row_; ++i) {
            for (int j = 0; j < col_; ++j) {
                longest = max(dfs(visited, i, j, -1), longest);
            }
        }
        return longest;
    }

    int dfs(vector<bool> &visited, int i, int j, int pre) {
        if (!valid(visited, i, j, pre)) {
            return 0;
        }
        int cur_index = i * col_ + j;
        if (memo_.find(cur_index) == memo_.end()) {
            int longest = 0;
            visited[cur_index] = true;
            longest = max(dfs(visited, i - 1, j, matrix_[i][j]), longest);//↑
            longest = max(dfs(visited, i, j - 1, matrix_[i][j]), longest);//←
            longest = max(dfs(visited, i, j + 1, matrix_[i][j]), longest);//→
            longest = max(dfs(visited, i + 1, j, matrix_[i][j]), longest);//↓
            visited[cur_index] = false;
            memo_[cur_index] = longest + 1;
        }
        return memo_[cur_index];
    }

    bool valid(vector<bool> &visited, int i, int j, int prev) {
        if (i < 0 || i >= row_) {
            return false;
        }
        if (j < 0 || j >= col_) {
            return false;
        }
        if (visited[i * col_ + j]) {
            return false;
        }
        if (matrix_[i][j] <= prev) {
            return false;
        }
        return true;
    }

private:
    int row_;
    int col_;
    map<int, int> memo_;
    vector<vector<int>> matrix_;
};