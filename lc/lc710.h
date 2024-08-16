#include <algorithm>
#include <random>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    Solution(int n, vector<int> &blacklist) {
        int i = n - 1;
        sort(blacklist.begin(), blacklist.end());
        for (int j = blacklist.size() - 1; j >= 0; --j) {
            if (valToVal_.find(i) == valToVal_.end()) {
                valToVal_[blacklist[j]] = i;
            } else {
                valToVal_[blacklist[j]] = valToVal_[i];
            }
            i--;
        }
        u_ = uniform_int_distribution<int>(0, n - blacklist.size());
    }

    int pick() {
        int r = u_(e_);
        if (valToVal_.find(r) != valToVal_.end()) {
            return valToVal_[r];
        }
        return r;
    }

private:
    unordered_map<int, int> valToVal_;
    uniform_int_distribution<int> u_;
    default_random_engine e_;
};
