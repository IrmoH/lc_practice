class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        long base = 5;
        while (base <= n) {
            ans += n / base;
            base *= 5;
        }
        return ans;
    }
};