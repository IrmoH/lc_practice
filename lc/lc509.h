#include <vector>


using namespace std;

//class Solution {
//public:
//    int fib(int N) {
//        if (N == 1 || N == 2) {
//            return 1;
//        }
//        return fib(N - 1) + fib(N - 2);
//    }
//};

class Solution {
public:
    int fib(int N) {
        if (N == 0 || N == 1) { return N; }
        int dp1 = 0;
        int dp2 = 1;
        for (int i = 2; i < N; ++i) {
            int temp = dp2;
            dp2 = dp1 + dp2;
            dp1 = temp;
        }
        return dp1 + dp2;
    }
};