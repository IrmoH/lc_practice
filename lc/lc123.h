#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int days = prices.size();
        int k = 2;
        vector<vector<pair<int, int>>> dp(days, vector<pair<int, int>>(k + 1, make_pair(0, 0)));
        for (int i = 0; i < days; ++i) {
            for (int j = 0; j < k + 1; ++j) {
                //base case
                if (i == 0) {
                    dp[i][j].first = 0;
                    dp[i][j].second = -prices[i];
                    continue;
                }
                if (j == 0) {
                    continue;
                }
                //状态选择
                dp[i][j].first = max(dp[i - 1][j].first, dp[i - 1][j].second + prices[i]);
                dp[i][j].second = max(dp[i - 1][j].second, dp[i - 1][j - 1].first - prices[i]);
            }
        }

        return dp[days - 1][k].first;
    }
};