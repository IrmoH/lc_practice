#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

class UnionFind {
public:
    UnionFind(int n) {
        parent_.resize(n);
        for (int i = 0; i < n; ++i) {
            parent_[i] = i;
        }
    }

    int find(int a) {
        if (parent_[a] != a) {
            parent_[a] = find(parent_[a]);
        }
        return parent_[a];
    }

    void unite(int a, int b) {
        parent_[find(a)] = find(b);
    }

    bool connect(int a, int b) {
        return find(a) == find(b);
    }

private:
    vector<int> parent_;
};

//class Solution {
//public:
//    int minCostConnectPoints(vector<vector<int>> &points) {
//        int n = static_cast<int>(points.size());
//        UnionFind uf(n);
//
//        vector<vector<int>> edges;
//        for (int i = 0; i < n; ++i) {
//            for (int j = i + 1; j < n; ++j) {
//                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
//                edges.push_back({i, j, cost});
//            }
//        }
//        //按照cost排列所有的边
//        sort(edges.begin(), edges.end(), [](vector<int> &a, vector<int> &b) { return a[2] < b[2]; });
//        int mst = 0;
//        //贪心，从最小cost开始连接，如果已经联通了，就不连接
//        for (auto edge: edges) {
//            int a = edge[0];
//            int b = edge[1];
//            int cost = edge[2];
//            if (!uf.connect(a, b)) {
//                uf.unite(a, b);
//                mst += cost;
//            }
//        }
//        return mst;
//
//    }
//};
////Kruskal最小生成树算法

class Solution {
public:
    struct Edge {
        int to;
        int cost;

        bool operator<(const Edge &other) const {
            return cost > other.cost;//最小堆， 如果要求最大堆：lhs.cost < rhs.cost
        }
    };

    int minCostConnectPoints(vector<vector<int>> &points) {
        int n = static_cast<int>(points.size());
        vector<vector<Edge>> edges(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j) {
                    int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                    edges[i].push_back(Edge{j, cost});
                }
            }
        }
        // 先随便找个节点开始
        priority_queue<Edge> pq(edges[0].begin(), edges[0].end());
        vector<bool> visited(n, false);
        visited[0] = true;

        int mst = 0;
        while (--n > 0) {
            Edge next;
            while (true) {
                next = pq.top();
                pq.pop();
                if (!visited[next.to]) {
                    break;
                }
            }

            for (auto edge: edges[next.to]) {
                if (!visited[edge.to]) {
                    pq.push(edge);
                }
            }
            visited[next.to] = true;
            mst += next.cost;
        }
        return mst;
    }
};
//prim最小生成树算法: 使用优先级队列寻找最小的边