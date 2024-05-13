#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &lhs, vector<int> &rhs) {
            if (lhs[0] == rhs[0]) {
                return lhs[1] > rhs[1];
            }
            return lhs[0] < rhs[0];
        });

        int left = intervals[0][0];
        int right = intervals[0][1];
        int n = intervals.size();
        vector<vector<int>> ans;
        for (int i = 1; i < n; ++i) {
            auto interval = intervals[i];
            //相交
            if (right >= interval[0] && right <= interval[1]) {
                right = interval[1];
            }
            //不相交
            if (right < interval[0]) {
                ans.push_back({left, right});
                left = interval[0];
                right = interval[1];
            }
        }
        ans.push_back({left, right});
        return ans;
    }
};