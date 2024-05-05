#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    Solution(vector<int> &nums) {
        for (int i = 0; i < nums.size(); ++i) {
            inverted_index_[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        auto vec = inverted_index_[target];
        auto r = rand() % vec.size();
        return vec[r];
    }

private:
    unordered_map<int, vector<int>> inverted_index_;
};
