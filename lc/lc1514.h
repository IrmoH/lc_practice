#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node) {
        auto graph = buildGraph(n, edges, succProb);

        vector<double> max_prob(n, 0);
        priority_queue<State> pq;
        pq.emplace(start_node, 1);
        max_prob[start_node] = 1;

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            if (cur.id_ == end_node) {
                return cur.prob_;
            }
            if (cur.prob_ < max_prob[cur.id_]) {
                continue;
            }

            for (auto &[next, next_prob]: graph[cur.id_]) {
                double prob = cur.prob_ * next_prob;
                if (prob > max_prob[next]) {
                    max_prob[next] = prob;
                    pq.emplace(next, prob);
                }
            }
        }
        return 0;
    }

private:
    struct State {
        int id_;
        double prob_;

        State(int id, double prob) : id_(id), prob_(prob) {}

        bool operator<(const State &other) const {
            return prob_ < other.prob_;
        }
    };

    vector<vector<pair<int, double>>> buildGraph(int n, vector<vector<int>> &edges, vector<double> &succProb) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); ++i) {
            auto a = edges[i][0];
            auto b = edges[i][1];
            auto weight = succProb[i];
            graph[a].emplace_back(b, weight);
            graph[b].emplace_back(a, weight);
        }
        return graph;
    }
};
// Dijkstra最短路径： BFS+优先级队列