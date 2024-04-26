#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int INF_MIN = -1e6;

    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        int k = 1;
        vector<vector<vector<int> > > dp(n + 1, vector<vector<int> >(k + 1, vector<int>(2, INF_MIN)));

        for (int i = 0; i < n + 1; ++i) {
            dp[i][0][0] = 0;
        }
        for (int j = 0; j < k + 1; ++j) {
            dp[0][j][0] = 0;
        }

        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < k + 1; ++j) {
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i - 1]);
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i - 1]);
            }
        }
        return dp[n][k][0];
    }
};