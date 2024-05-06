#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        int ab = lcm(a, b);
        int bc = lcm(b, c);
        int ac = lcm(a, c);
        int abc = lcm(ab, c);

        int left = 1;
        int right = 2e9;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int num = mid / a + mid / b + mid / c - mid / ab - mid / bc - mid / ac + mid / abc;
            if (num < n) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        while (!isUgly(left, a, b, c)) {
            left++;
        }
        return left;
    }

private:
    bool isUgly(int n, int a, int b, int c) {
        return n % a == 0 || n % b == 0 || n % c == 0;
    }
};