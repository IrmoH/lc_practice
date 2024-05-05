#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums) {
        int n = static_cast<int>(nums.size());
        int dup = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1;
            if (nums[index] < 0) {
                dup = abs(nums[i]);
            } else {
                nums[index] = -nums[index];
            }
        }
        int missing = 1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                missing = i + 1;
            }
        }
        return {dup, missing};
    }
};