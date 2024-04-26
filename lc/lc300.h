#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> top;
        for (int num: nums) {
            int start = 0;
            int end = top.size();
            while (start < end) {
                int mid = start + (end - start) / 2;
                if (top[mid] < num) {
                    start = mid + 1;
                } else {
                    end = mid;
                }
            }
            if (start == top.size()) {
                top.push_back(num);
            } else {
                top[start] = num;
            }
        }
        return top.size();
    }
};