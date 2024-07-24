#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }

        int i = 0;
        int j = nums.size() - 1;

        while (i < j) {
            int mid = i + (j - i) / 2;
            if (target == nums[mid]) {
                j = mid;
            } else if (target < nums[mid]) {
                j = mid;
            } else if (target > nums[mid]) {
                i = mid + 1;
            }
        }
        if (nums[i] != target) {
            return {-1, -1};
        }

        int left = i;

        i = 0;
        j = nums.size();

        while (i < j) {
            int mid = i + (j - i) / 2;
            if (target == nums[mid]) {
                i = mid + 1;
            } else if (target < nums[mid]) {
                j = mid;
            } else if (target > nums[mid]) {
                i = mid + 1;
            }
        }
        return {left, i - 1};
    }
};