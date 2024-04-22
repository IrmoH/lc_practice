#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int ans = nums[0];
        int dp_0 = INT_MIN;
        int dp_1 = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            if (dp_0 <= 0) {
                dp_1 = nums[i - 1];
            } else {
                dp_1 = nums[i - 1] + dp_0;
            }
            ans = max(ans, dp_1);
            dp_0 = dp_1;
        }
        return ans;
    }
};