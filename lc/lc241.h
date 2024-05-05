#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<string, vector<int>> memo_;

    vector<int> diffWaysToCompute(string expression) {
        if (memo_.find(expression) != memo_.end()) {
            return memo_[expression];
        }
        vector<int> res;
        for (int i = 0; i < expression.size(); ++i) {
            char c = expression[i];
            if (c == '+' || c == '-' || c == '*') {
                //分
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                //治
                for (auto l: left) {
                    for (auto r: right) {
                        if (c == '+') {
                            res.push_back(l + r);
                        } else if (c == '-') {
                            res.push_back(l - r);
                        } else {
                            res.push_back(l * r);
                        }
                    }
                }
            }
        }

        //base case 计算(5)的情况
        if (res.empty()) {
            res.push_back(stoi(expression));
        }
        memo_[expression] = res;
        return res;
    }
};
//分治