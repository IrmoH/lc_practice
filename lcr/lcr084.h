#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> track;

    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, used);
        return res;
    }

    void backtrack(vector<int> &nums, vector<bool> &used) {
        if (track.size() == nums.size()) {
            res.push_back(track);
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                continue;
            }

            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }

            used[i] = true;
            track.push_back(nums[i]);
            backtrack(nums, used);
            used[i] = false;
            track.pop_back();
        }
    }
};