#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    // f返回当每天运载能力为x时，需要花费的天数
    int f(vector<int> &weights, int x) {
        int days = 1;
        int k = x;
        for (int weight: weights) {
            if (x < weight) {
                return -1;
            }
            if (k < weight) {
                days++;
                k = x;
            }
            k -= weight;
        }
        return days;
    }

    // 二分求最左侧边界
    int shipWithinDays(vector<int> &weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = 25e6 + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (f(weights, mid) <= days) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};