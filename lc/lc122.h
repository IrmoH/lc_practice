#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1e6));

        for (int i = 0; i < n + 1; ++i) {
            dp[i][0] = 0;
        }

        for (int i = 1; i < n + 1; ++i) {
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i - 1]);
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1]);
        }
        return dp[n][0];
    }
};