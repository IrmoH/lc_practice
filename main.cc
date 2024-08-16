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

#include "lc/lc1081.h"

int main() {
    string str = "bcabc";
    Solution s;
    s.smallestSubsequence(str);
    return 0;
}
