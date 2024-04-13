#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, 10001);
        dp[0] = 0;
        for (int i = 0; i < amount + 1; ++i) {
            for (auto coin: coins) {
                if (i - coin < 0) {
                    continue;
                }
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return dp[amount] == 10001 ? -1 : dp[amount];
    }
};