#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> count(255, 0);
        vector<bool> inStack(255, false);
        stack<char> stk;

        for (char c: s) {
            count[c]++;
        }
        for (char c: s) {
            count[c]--;
            if (inStack[c]) {
                continue;
            }
            while (!stk.empty() && stk.top() > c) {
                if (count[stk.top()] == 0) {
                    break;
                }
                inStack[stk.top()] = false;
                stk.pop();
            }

            stk.push(c);
            inStack[c] = true;
        }

        string ans;
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};