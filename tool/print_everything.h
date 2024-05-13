#include <iostream>
#include <vector>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
void print(std::vector<T> &vec) {
    for (auto item: vec) {
        cout << item << " ";
    }
    cout << endl;
}

template<typename T>
void print(T t) {
    cout << t << endl;
}

template<typename K, typename V>
void print(std::unordered_map<K, V> &map) {
    cout << "map: {";
    for (auto &[key, value]: map) {
        cout << "[k:" << key << " v:" << value << "] ";
    }
    cout << "}" << endl;
}