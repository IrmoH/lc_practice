#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minOperations(vector<int> &nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        auto target = sum - x;

        int window = 0;
        int left = 0;
        int right = 0;
        int max_w = -1;
        while (right < nums.size()) {
            window += nums[right];
            right++;

            while (left < right && window > target) {
                window -= nums[left];
                left++;
            }
            if (window == target) {
                max_w = max(max_w, right - left);
            }
        }
        if (max_w == -1) {
            return max_w;
        }
        return nums.size() - max_w;
    }
};