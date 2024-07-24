#include <vector>

using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int upper_bound = 0;
        int right_bound = n - 1;
        int left_bound = 0;
        int lower_bound = m - 1;

        vector<int> res;
        while (res.size() < m * n) {
            if (upper_bound <= lower_bound) {
                for (int i = left_bound; i <= right_bound; ++i) {
                    res.push_back(matrix[upper_bound][i]);
                }
                upper_bound++;
            }
            if (left_bound <= right_bound) {
                for (int i = upper_bound; i <= lower_bound; ++i) {
                    res.push_back(matrix[i][right_bound]);
                }
                right_bound--;
            }
            if (upper_bound <= lower_bound) {
                for (int i = right_bound; i >= left_bound; --i) {
                    res.push_back(matrix[lower_bound][i]);
                }
                lower_bound--;
            }
            if (left_bound <= right_bound) {
                for (int i = lower_bound; i >= upper_bound; --i) {
                    res.push_back(matrix[i][left_bound]);
                }
                left_bound++;
            }
        }
        return res;
    }
};