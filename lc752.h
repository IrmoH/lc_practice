#include <queue>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        queue<string> q;
        string init = "0000";
        q.push(init);

        set<string> visited;
        visited.insert(init);
        int step = 0;

        visited.insert(deadends.begin(),deadends.end());
        while (!q.empty()) {
            auto size = q.size();
            for (int i = 0; i < size; ++i) {
                auto cur = q.front();
                q.pop();

                if (cur == target) {
                    return step;
                }
                for (int j = 0; j < 4; ++j) {
                    auto dial_up = dial(cur, j, true);
                    if (visited.count(dial_up) == 0) {
                        q.push(dial_up);
                        visited.insert(dial_up);
                    }
                    auto dial_down = dial(cur, j, false);
                    if (visited.count(dial_down) == 0) {
                        q.push(dial_down);
                        visited.insert(dial_down);
                    }
                }
            }
            step++;
        }
        return -1;
    }

    string dial(string lock, int i, bool up) {
        if (up) {
            if (lock[i] == '9') {
                lock[i] = '0';
            } else {
                lock[i]++;
            }
        } else {
            if (lock[i] == '0') {
                lock[i] = '9';
            } else {
                lock[i]--;
            }
        }
        return lock;
    }
};