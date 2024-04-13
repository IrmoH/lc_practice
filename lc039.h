#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<int> track;
        backtrack(candidates, track, target, 0);
        return ans;
    }

    void backtrack(vector<int> &candidates, vector<int> &track, int target, int start) {
        if (target == 0) {
            ans.push_back(track);
            return;
        }
        if (target < 0) {
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            track.push_back(candidates[i]);
            backtrack(candidates, track, target - candidates[i], i);
            track.pop_back();
        }
    }
};
