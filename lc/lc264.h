#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long> ugly_nums(n + 1);
        int a = 1;
        int b = 1;
        int c = 1;

        int pa = 1;
        int pb = 1;
        int pc = 1;

        int p = 1;
        while (p <= n) {
            int m = min(a, min(b, c));
            ugly_nums[p] = m;
            p++;

            if (a == m) {
                a = ugly_nums[pa] * 2;
                pa++;
            }
            if (b == m) {
                b = ugly_nums[pb] * 3;
                pb++;
            }
            if (c == m) {
                c = ugly_nums[pc] * 5;
                pc++;
            }
        }
        return ugly_nums[n];
    }
};