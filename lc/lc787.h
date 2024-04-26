#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        //dp[k][n]表示恰好经过k+1次航班, 从起点src到达目的地n所需的最小花费
        vector<vector<int>> dp(k + 2, vector<int>(n, INF));
        dp[0][src] = 0;
        for (int i = 1; i <= k + 1; ++i) {
            for (auto &flight: flights) {
                auto from = flight[0];
                auto to = flight[1];
                auto price = flight[2];
                dp[i][to] = min(dp[i][to], dp[i - 1][from] + price);
            }
        }
        //由于有可能小于k+1次航班, 花费最小, 因此求min(dp[i][dst]), i属于k+1
        int ans = INF;
        for (int i = 1; i <= k + 1; ++i) {
            ans = min(ans, dp[i][dst]);
        }
        return ans == INF ? -1 : ans;
    }

private:
    int INF = 1e4 * 101 + 1;
};