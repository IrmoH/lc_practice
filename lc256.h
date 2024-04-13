#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> track;
        backtrack(track, 1, n, k);
        return res;
    }

    void backtrack(vector<int> &track, int start, int n, int k) {
        if (track.size() > k) {
            return;
        }
        //终止条件
        if (track.size() == k && n == 0) {
            res.push_back(track);
            return;
        }

        for (int i = start; i < 10; i++) {
            //排除不合法选择
            if (n - i < 0) {
                continue;
            }
            //做选择
            track.push_back(i);
            //进入下一层决策树
            backtrack(track, i + 1, n - i, k);
            //撤销选择
            track.pop_back();
        }
    }
};