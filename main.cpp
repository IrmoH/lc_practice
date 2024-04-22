#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "lc787.h"

using namespace std;

template<typename T>
void print(vector<T> vec) {
    for (auto item: vec) {
        cout << item << " ";
    }
    cout << endl;
}

template<typename T>
void print(T t) {
    cout << t << endl;
}


int main() {
    Solution s;
    vector<vector<int>> flights{{0, 1, 100},
                                {1, 2, 100},
                                {2, 0, 100},
                                {1, 3, 600},
                                {2, 3, 200}};
    auto res = s.findCheapestPrice(4, flights, 0, 3, 1);
    print(res);
    flights = {{3, 4, 4},
               {2, 5, 6},
               {4, 7, 10},
               {9, 6, 5},
               {7, 4, 4},
               {6, 2, 10},
               {6, 8, 6},
               {7, 9, 4},
               {1, 5, 4},
               {1, 0, 4},
               {9, 7, 3},
               {7, 0, 5},
               {6, 5, 8},
               {1, 7, 6},
               {4, 0, 9},
               {5, 9, 1},
               {8, 7, 3},
               {1, 2, 6},
               {4, 1, 5},
               {5, 2, 4},
               {1, 9, 1},
               {7, 8, 10},
               {0, 4, 2},
               {7, 2, 8}};
    res = s.findCheapestPrice(10, flights, 6, 0, 7);
    print(res);
    return 0;
}