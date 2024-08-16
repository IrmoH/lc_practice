#include <algorithm>
#include <random>
#include <vector>
using namespace std;

class Solution {
public:
    Solution(vector<int> &w) {
        pre_sum_ = vector<int>(w.size(), 0);
        pre_sum_[0] = w[0];
        for (int i = 1; i < w.size(); ++i) {
            pre_sum_[i] = pre_sum_[i - 1] + w[i];
        }
        u_ = uniform_int_distribution<int>(0, pre_sum_.back());
    }

    int pickIndex() {
        int r = u_(e);
        int left = 0;
        int right = pre_sum_.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (r == pre_sum_[mid]) {
                return left;
            } else if (r > pre_sum_[mid]) {
                left = mid + 1;
            } else if (r < pre_sum_[mid]) {
                right = mid;
            }
        }
        return left;
    }

private:
    uniform_int_distribution<int> u_;
    default_random_engine e;
    vector<int> pre_sum_;
};