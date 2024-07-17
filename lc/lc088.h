#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int k = nums1.size() - 1;
        m--;
        n--;

        while (k >= 0) {
            if (m < 0) {
                nums1[k--] = nums2[n--];
                continue;
            }
            if (n < 0) {
                nums1[k--] = nums1[m--];
                continue;
            }
            if (nums1[m] < nums2[n]) {
                nums1[k--] = nums2[n--];
            } else {
                nums1[k--] = nums1[m--];
            }
        }
    }
};