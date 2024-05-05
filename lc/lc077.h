#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> combine(int n, int k) {
        vector<int> track;
        backtrack(track, n, k, 1);
        return ans;
    }

    void backtrack(vector<int> &track, int n, int k, int start) {
        if (track.size() == k) {
            ans.push_back(track);
            return;
        }

        for (int i = start; i <= n; ++i) {
            track.push_back(i);
            backtrack(track, n, k, i + 1);
            track.pop_back();
        }
    }
};
//回溯