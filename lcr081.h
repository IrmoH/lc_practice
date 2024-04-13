#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> track;

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtrack(candidates, target, 0);
        return res;
    }

    void backtrack(vector<int> &candidates, int target, int start) {
        if (target == 0) {
            res.push_back(track);
            return;
        }
        for (int i = start; i < candidates.size(); ++i) {
            if (target - candidates[i] < 0) {
                return;
            }

            track.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i);
            track.pop_back();
        }
    }
};