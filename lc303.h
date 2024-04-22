#include <vector>
#include <algorithm>

using namespace std;

class NumArray {
public:
    NumArray(vector<int> &nums) {
        size = nums.size();
        sums.resize(size);
        int sum = 0;
        for (int i = size - 1; i >= 0; --i) {
            sum += nums[i];
            sums[i] = sum;
        }
    }

    int sumRange(int left, int right) {
        if (right == size - 1) {
            return sums[left];
        }
        return sums[left] - sums[right + 1];
    }

private:
    vector<int> sums;
    int size;
};
