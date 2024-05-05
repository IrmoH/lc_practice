#include <vector>
#include <queue>
#include <climits>
#include <cmath>

using namespace std;

class Solution {
public:
    //求节点k到其他节点(1~n)的最小距离
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        //求最小值，所以初始化为最大值
        vector<int> min_dist(n + 1, INT_MAX);
        min_dist[k] = 0;
        vector<vector<pair<int, int>>> graph = buildGraph(times, n);

        priority_queue<State> pq;
        //从起点开始BFS
        pq.emplace(k, 0);

        while (!pq.empty()) {
            State cur = pq.top();
            pq.pop();
            //相邻节点
            for (auto &[next, next_dist]: graph[cur.to_]) {
                int cur_dist = next_dist + cur.dist_;
                //距离更短才放进队列
                if (cur_dist < min_dist[next]) {
                    min_dist[next] = cur_dist;
                    pq.emplace(next, cur_dist);
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (min_dist[i] == INT_MAX) {
                return -1;
            }
            ans = max(ans, min_dist[i]);
        }
        return ans;
    }

private:
    struct State {
        int to_;
        int dist_;

        State(int to, int cost) {
            to_ = to;
            dist_ = cost;
        }

        bool operator<(const State &other) const { return dist_ > other.dist_; }
    };

    vector<vector<pair<int, int>>> buildGraph(vector<vector<int>> &times, int n) {
        vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());
        for (auto edge: times) {
            auto from = edge[0];
            auto to = edge[1];
            auto cost = edge[2];
            graph[from].emplace_back(to, cost);
        }
        return graph;
    }
};
// Dijkstra最短路径： BFS+优先级队列