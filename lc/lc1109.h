#include <vector>

using namespace std;

class Difference {
public:
    Difference(const vector<int> &nums) {
        diff.resize(nums.size(), 0);
        diff[0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            diff[i] = nums[i] - diff[i - 1];
        }
    }

    void increment(int i, int j, int val) {
        diff[i] += val;
        if (j < diff.size() - 1) {
            diff[j + 1] -= val;
        }
    }

    vector<int> result() {
        vector<int> res(diff.size(), 0);
        res[0] = diff[0];
        for (int i = 1; i < diff.size(); ++i) {
            res[i] = diff[i] + res[i - 1];
        }
        return res;
    }

private:
    vector<int> diff;
};


class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>> &bookings, int n) {
        vector<int> nums(n, 0);
        Difference diff(nums);
        for (auto booking: bookings) {
            diff.increment(booking[0] - 1, booking[1] - 1, booking[2]);
        }
        return diff.result();
    }
};