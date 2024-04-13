#include <iostream>
#include <map>
#include "lc547.h"

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
    vector<vector<int>> isConnected{{1, 1, 1},
                                    {1, 1, 1},
                                    {1, 1, 1}};
    auto res = s.findCircleNum(isConnected);
    print(res);
    return 0;
}