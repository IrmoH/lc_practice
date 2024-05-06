#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int> &primes) {
        vector<int> ugly_nums(n + 1);
        int k = primes.size();
        vector<int> primes_points(k, 1);
        vector<long> primes_times(k, 1);

        int p = 1;
        while (p <= n) {
            auto m = *min_element(primes_times.begin(), primes_times.end());
            ugly_nums[p] = static_cast<int>(m);
            p++;

            for (int i = 0; i < k; ++i) {
                if (m == primes_times[i]) {
                    primes_times[i] = static_cast<long>(primes[i]) * ugly_nums[primes_points[i]];
                    primes_points[i]++;
                }
            }
        }

        return ugly_nums[n];
    }
};