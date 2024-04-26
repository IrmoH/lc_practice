#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool predictTheWinner(vector<int> &nums) {
        return stoneGame(nums);
    }

private:
    bool stoneGame(vector<int> &piles) {
        int n = piles.size();
        // dp[i][j].first表示在(i,j)范围内先手选的最大值
        // dp[i][j].second表示在(i,j)范围内后手选的最大值
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, make_pair(0, 0)));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = {piles[i], 0};
        }

        for (int i = n - 2; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                int left = piles[i] + dp[i + 1][j].second;
                int right = piles[j] + dp[i][j - 1].second;

                if (left >= right) { // 先手选左边
                    dp[i][j].first = left;
                    dp[i][j].second = dp[i + 1][j].first; //后手就变成了下一步的先手
                } else {// 先手选右边
                    dp[i][j].first = right;
                    dp[i][j].second = dp[i][j - 1].first;
                }
            }
        }
        return dp[0][n - 1].first >= dp[0][n - 1].second;
    }
};