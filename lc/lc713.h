#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        int left = 0;
        int right = 0;
        int window = 1;

        int res = 0;
        while (right < nums.size()) {
            window *= nums[right];
            right++;

            while (left < right && window >= k) {
                window /= nums[left];
                left++;
            }
            res += right - left;
        }

        return res;
    }
};