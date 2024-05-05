#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    Solution(vector<int> &nums) {
        origin_ = nums;
        nums_ = nums;
    }

    vector<int> reset() {
        nums_ = origin_;
        return nums_;
    }

    vector<int> shuffle() {
        int n = nums_.size();
        for (int i = 0; i < n; ++i) {
            int r = i + rand() % (n - i);
            swap(nums_[i], nums_[r]);
        }
        return nums_;
    }

private:
    vector<int> origin_;
    vector<int> nums_;
};
