#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int f(vector<int> &piles, int k) {
        int hours = 0;
        for (auto pile: piles) {
            hours += (pile + k - 1) / k;
        }
        return hours;
    }

    int minEatingSpeed(vector<int> &piles, int h) {
        int left = 1;
        int right = 1e9 + 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (f(piles, mid) <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};