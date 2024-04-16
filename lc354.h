#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &left, vector<int> &right) {
            return left[0] == right[0] ? left[1] > right[1] : left[0] < right[0];
        });

        vector<int> top;
        for (auto &envelope: envelopes) {
            auto todo = envelope[1];
            int start = 0;
            int end = top.size();
            while (start < end) {
                int mid = start + (end - start) / 2;
                if (todo > top[mid]) {
                    start = mid + 1;
                } else {
                    end = mid;
                }
            }
            if (start == top.size()) {
                top.push_back(todo);
            } else {
                top[start] = todo;
            }
        }

        return top.size();
    }
};