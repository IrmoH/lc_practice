#include <cmath>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff) {
        int left = 0;
        int right = 0;
        set<int> window;
        while (right < nums.size()) {
            auto cur = nums[right];
            //寻找大于等于cur - valueDiff的第一个元素。 PS：set保证元素升序
            auto lower = window.lower_bound(cur - valueDiff);
            if (lower != window.end() && abs(*lower - cur) <= valueDiff) {
                return true;
            }

            window.insert(cur);
            right++;
            //收缩窗口，窗口的大小总是为indexDiff
            while (right - left > indexDiff) {
                window.erase(nums[left]);
                left++;
            }
        }
        return false;
    }
};
