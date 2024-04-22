#include <vector>

using namespace std;

class Solution {
public:
    // 关键：反着来计算
    int calculateMinimumHP(vector<vector<int>> &dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        // dp[i][j]表示骑士从(i,j)到达右下角所需的最小生命值
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m - 1][n - 1] = dungeon[m - 1][n - 1] > 0 ? 1 : 1 - dungeon[m - 1][n - 1];
        for (int i = m - 2; i >= 0; --i) {
            dp[i][n - 1] = dp[i + 1][n - 1] - dungeon[i][n - 1];
            if (dp[i][n - 1] <= 0) {
                dp[i][n - 1] = 1;
            }
        }

        for (int j = n - 2; j >= 0; --j) {
            dp[m - 1][j] = dp[m - 1][j + 1] - dungeon[m - 1][j];
            if (dp[m - 1][j] <= 0) {
                dp[m - 1][j] = 1;
            }
        }

        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j >= 0; --j) {
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                if (dp[i][j] <= 0) {
                    dp[i][j] = 1;
                }
            }
        }

        return dp[0][0];
    }
};