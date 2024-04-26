#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        sz_ = ring.size();
        ring_ = ring;
        key_ = key;
        memo_ = vector<vector<int>>(ring.size(), vector<int>(key.size(), 0));
        return dp(0, 0);
    }

private:
    int sz_;
    string ring_;
    string key_;
    vector<vector<int>> memo_;

    int dp(int pos, int j) {
        if (j >= key_.size()) {
            return 0;
        }
        if (ring_[pos] == key_[j]) {
            return 1 + dp(pos, j + 1);
        }
        if (memo_[pos][j] != 0) {
            return memo_[pos][j];
        }
        int clockwise_step = rotateStep(key_[j], pos);
        int anticlockwise_step = rotateStep(key_[j], pos, false);

        int res = min(clockwise_step + dp((pos + clockwise_step) % sz_, j),
                      anticlockwise_step + dp((pos - anticlockwise_step + sz_) % sz_, j));
        memo_[pos][j] = res;
        return res;
    }

    int rotateStep(char &c, int pos, bool clockwise = true) {
        int step = 0;
        if (clockwise) {
            for (int i = pos; i < pos + sz_; ++i) {
                if (ring_[i % sz_] == c) {
                    break;
                }
                step++;
            }
        } else {
            for (int j = pos; j > pos - sz_; --j) {
                if (ring_[(j + sz_) % sz_] == c) {
                    break;
                }
                step++;
            }
        }
        return step;
    }
};