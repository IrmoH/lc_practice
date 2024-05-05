#include <vector>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int row = static_cast<int>(heights.size());
        int col = static_cast<int>(heights[0].size());
        vector<vector<int>> min_hp(row, vector<int>(col, INT_MAX));

        priority_queue<State> pq;

        //起点为(0,0)
        pq.emplace(0, 0, 0);
        min_hp[0][0] = 0;
        vector<vector<int>> directions{{-1, 0},
                                       {0,  -1},
                                       {0,  1},
                                       {1,  0}};// 定义上下左右
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if (cur.i_ == row - 1 && cur.j_ == col - 1) {
                return cur.hp_;
            }

            for (auto direction: directions) {
                int i = cur.i_ + direction[0];
                int j = cur.j_ + direction[1];
                if (i < 0 || i >= row || j < 0 || j >= col) {
                    //越界
                    continue;
                }
                int next_hp = max(cur.hp_, abs(heights[cur.i_][cur.j_] - heights[i][j]));
                if (next_hp < min_hp[i][j]) {
                    min_hp[i][j] = next_hp;
                    pq.emplace(i, j, next_hp);
                }
            }
        }

        return -1;
    }

private:
    struct State {
        int hp_;
        int i_;
        int j_;

        State(int i, int j, int hp) {
            i_ = i;
            j_ = j;
            hp_ = hp;
        }

        bool operator<(const State &other) const {
            return hp_ > other.hp_;
        }
    };
};
// Dijkstra最短路径： BFS+优先级队列