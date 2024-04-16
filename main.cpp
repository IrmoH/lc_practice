#include <iostream>
#include <map>
#include "lc354.h"

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
    vector<vector<int>> envelopes{{30, 50},
                                  {12, 2},
                                  {3,  4},
                                  {12, 15}};
    auto res = s.maxEnvelopes(envelopes);
    print(res);
    return 0;
}