#include <cstring>
#include <deque>
#include <execution>
#include <forward_list>
#include <functional>
#include <iostream>
#include <list>
#include <mutex>
#include <queue>
#include <random>
#include <string>

#include "tool/algorithm.h"
#include "tool/print_everything.h"
#include "tool/thread_pool.h"

#include "lc/lc713.h"

int main() {
    Solution s;
    vector<int> vec{10, 9, 10, 4, 3, 8, 3, 3, 6, 2, 10, 10, 9, 3};
    auto res = s.numSubarrayProductLessThanK(vec, 19);
    print(res);
    return 0;
}
