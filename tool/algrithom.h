#include <iostream>

using namespace std;

// 计算最大公因数（辗转相除/欧几里得算法）
int gcd(int a, int b) {
    if (a < b) {
        // 保证 a > b
        return gcd(b, a);
    }
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

//计算最小公倍数
int lcm(int a, int b) {
    // 最小公倍数就是乘积除以最大公因数
    return a * b / gcd(a, b);
}