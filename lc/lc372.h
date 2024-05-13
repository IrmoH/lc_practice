#include <vector>

using namespace std;

class Solution {
public:
    int superPow(int a, vector<int> &b) {
        if (b.empty()) {
            return 1;
        }
        int last = b.back();
        b.pop_back();
        int p1 = pow(a, last);
        int p2 = pow(superPow(a, b), 10);
        return (p1 * p2) % base;
    }

private:
    int base = 1337;

    int pow(int a, int k) {
        if (k == 0) {
            return 1;
        }
        a = a % base;
        if (k % 2 == 0) {
            int sub = pow(a, k / 2);
            return (sub * sub) % base;
        } else {
            return (a * pow(a, k - 1)) % base;
        }
    }
};