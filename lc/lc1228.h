#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &lhs, vector<int> &rhs) {
            if (lhs[0] == rhs[0]) {
                return lhs[1] > rhs[1];
            }
            return lhs[0] < rhs[0];
        });

        int right = intervals[0][1];
        int n = intervals.size();
        int d = 0;
        for (int i = 1; i < n; ++i) {
            auto interval = intervals[i];
            if (right >= interval[1]) {
                d++;
            } else {
                right = interval[1];
            }
        }
        return n - d;
    }
};