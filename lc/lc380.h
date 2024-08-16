#include <random>
#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {}

    bool insert(int val) {
        if (table.find(val) != table.end()) {
            return false;
        }
        vec.push_back(val);
        table[val] = vec.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (table.find(val) == table.end()) {
            return false;
        }
        size_t index = table[val];
        int last_element = vec.back();
        table[last_element] = index;

        swap(vec[index], vec.back());
        vec.pop_back();
        table.erase(val);
        return true;
    }

    int getRandom() {
        uniform_int_distribution<int> u(0, vec.size() - 1);
        return vec[u(e)];
    }

private:
    vector<int> vec;
    unordered_map<int, size_t> table;
    default_random_engine e;
};
