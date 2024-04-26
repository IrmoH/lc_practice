#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }
        int half = sum / 2;
        int n = nums.size();
        vector<bool> dp(half + 1, false);
        dp[0] = true;
        for (int i = 1; i < n + 1; ++i) {
            for (int j = half; j > 1; --j) {
                if (j - nums[i - 1] >= 0) {
                    dp[j] = dp[j] || dp[j - nums[i - 1]];
                }
            }
        }

        return dp[half];
    }
};