#include <vector>

using namespace std;

class Solution {
public:
    //从左上角开始移动，只能向左或向下移动
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int j = matrix[0].size() - 1;
        while (j >= 0 && i < matrix.size()) {
            int num = matrix[i][j];
            if (num == target) {
                return true;
            } else if (num > target) {
                j--;
            } else if (num < target) {
                i++;
            }
        }
        return false;
    }
};