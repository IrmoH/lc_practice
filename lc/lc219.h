#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        int left = 0, right = 0;
        unordered_set<int> window;
        while (right < nums.size()) {
            int cur = nums[right];
            if (window.find(cur) != window.end()) {
                return true;
            }
            window.insert(cur);
            right++;

            while (right - left > k) {
                window.erase(nums[left]);
                left++;
            }
        }
        return false;
    }
};