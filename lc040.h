#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        vector<int> track;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, track, target, 0);
        return ans;
    }

    void backtrack(vector<int> &candidates, vector<int> &track, int target, int start) {
        if (target == 0) {
            ans.push_back(track);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            //若子集和超过 target ，则直接结束循环
            //这是因为数组已排序，后边元素更大，子集和一定超过 target
            if (target - candidates[i] < 0) {
                break;
            }
            //如果该元素与左边元素相等，说明该搜索分支重复，直接跳过
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            track.push_back(candidates[i]);
            backtrack(candidates, track, target - candidates[i], i + 1);
            track.pop_back();
        }
    }
};