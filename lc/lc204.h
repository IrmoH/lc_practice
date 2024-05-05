#include <vector>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> is_prime(n, true);
        for (int i = 2; i < sqrt(n); ++i) {
            if (is_prime[i]) {
                for (int j = i * i; j < n; j = j + i) {
                    is_prime[j] = false;
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (is_prime[i]) {
                count++;
            }
        }
        return count;
    }
};