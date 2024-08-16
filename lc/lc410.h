#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    // 当最大和为x时，f返回拆分的非空的连续子数组个数
    int f(vector<int> &nums, int x) {
        int res = 1;
        int sum = 0;
        for (int num: nums) {
            if (num > x) {
                return -1;
            }
            sum += num;
            if (sum > x) {
                res++;
                sum = num;
            }
        }
        return res;
    }

    int splitArray(vector<int> &nums, int k) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0) + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            auto y = f(nums, mid);
            if (y > k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};