#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        //0往右，1往下，2往左，3往上
        vector<int> direct{0, n - 1, n - 1, 0};
        int k = 1;
        while (k <= n * n) {
            if (direct[0] <= direct[2]) {
                for (int j = direct[3]; j <= direct[1]; ++j) {
                    matrix[direct[0]][j] = k++;
                }
                direct[0]++;
            }
            if (direct[3] <= direct[1]) {
                for (int i = direct[0]; i <= direct[2]; ++i) {
                    matrix[i][direct[1]] = k++;
                }
                direct[1]--;
            }
            if (direct[0] <= direct[2]) {
                for (int j = direct[1]; j >= direct[3]; --j) {
                    matrix[direct[2]][j] = k++;
                }
                direct[2]--;
            }
            if (direct[3] <= direct[1]) {
                for (int i = direct[2]; i >= direct[0]; --i) {
                    matrix[i][direct[3]] = k++;
                }
                direct[3]++;
            }
        }
        return matrix;
    }
};