#include <vector>

using namespace std;

class Solution {
public:
    int longestOnes(vector<int> &nums, int k) {
        int left = 0;
        int right = 0;
        // 记录窗口中 1 的出现次数
        int ones = 0;
        int res = 0;
        while (right < nums.size()) {
            if (nums[right] == 1) {
                ones++;
            }
            right++;

            // 当窗口中需要替换的 0 的数量大于 k，缩小窗口
            while (right - left - ones > k) {
                if (nums[left] == 1) {
                    ones--;
                }
                left++;
            }
            // 此时一定是一个合法的窗口，求最大窗口长度
            res = max(res, right - left);
        }
        return res;
    }
};