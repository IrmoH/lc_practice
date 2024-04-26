#include <vector>

using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        sums = vector<vector<int>>(row + 1, vector<int>(col + 1, 0));

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                sums[i + 1][j + 1] = matrix[i][j] + sums[i + 1][j] + sums[i][j + 1] - sums[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2 + 1][col2 + 1] - sums[row2 + 1][col1] - sums[row1][col2 + 1] + sums[row1][col1];
    }

private:
    vector<vector<int>> sums;
};
