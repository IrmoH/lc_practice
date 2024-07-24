#include <vector>

using namespace std;


class Solution {
public:
    //记录结果
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int> &nums) {
        //记录路径
        vector<int> track;
        res.reserve(nums.size() * (nums.size() - 1));
        //记录元素是否被选择
        vector<bool> used(nums.size(), false);
        backtrack(nums, track, used);
        return res;
    }

    //路径：记录在track
    //选择列表：用used做标记，false代表没有被选过的
    //结束条件：当track长度
    void backtrack(vector<int> &nums, vector<int> &track, vector<bool> &used) {

        //结束条件
        if (track.size() == nums.size()) {
            res.push_back(track);
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                continue;
            }
            //做选择
            track.push_back(nums[i]);
            used[i] = true;

            //进入下一层决策树
            backtrack(nums, track, used);

            //取消选择
            track.pop_back();
            used[i] = false;
        }
    }
};