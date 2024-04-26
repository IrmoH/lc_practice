#include <iostream>
#include "tool/print_everything.h"
#include "lc/lc460.h"

int main() {
    LFUCache lfu(3);
    lfu.put(1, 1);
    lfu.put(2, 2);
    lfu.put(3, 3);
    lfu.put(4, 4);
    print(lfu.get(4));
    print(lfu.get(3));
    print(lfu.get(2));
    print(lfu.get(1));
    lfu.put(5, 5);
    print(lfu.get(1));
    print(lfu.get(2));
    print(lfu.get(3));
    print(lfu.get(4));
    print(lfu.get(5));
    return 0;
}