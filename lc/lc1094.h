#include <vector>

using namespace std;

#define FARTHEST 10001
class Difference {
public:
    Difference(int capacity) {
        diff.resize(FARTHEST, 0);
        diff[0] = capacity;
    }

    void increment(int i, int j, int val) {
        diff[i] -= val;
        if (j < FARTHEST) {
            diff[j] += val;
        }
    }

    bool result() {
        if (diff[0] < 0) {
            return false;
        }
        vector<int> res(FARTHEST, 0);
        res[0] = diff[0];
        for (int i = 1; i < FARTHEST; ++i) {
            res[i] = diff[i] + res[i - 1];
            if (res[i] < 0) {
                return false;
            }
        }
        return true;
    }

private:
    vector<int> diff;
};

class Solution {
public:
    bool carPooling(vector<vector<int>> &trips, int capacity) {
        Difference difference(capacity);
        for (auto trip: trips) {
            int numPassengers = trip[0];
            int from = trip[1];
            int to = trip[2];
            difference.increment(from, to, numPassengers);
        }
        return difference.result();
    }
};