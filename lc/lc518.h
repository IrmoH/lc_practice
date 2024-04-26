#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int> &coins) {
        int n = coins.size();
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i = 1; i < n + 1; ++i) {
            for (int j = 1; j < amount + 1; ++j) {
                if (j - coins[i - 1] >= 0) {
                    dp[j] = dp[j] + dp[j - coins[i - 1]];
                }
            }
        }
        return dp[amount];
    }
};