#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int a) {
        if (parent[a] != a) {
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }

    void unite(int a, int b) {
        parent[find(a)] = find(b);
    }

private:
    vector<int> parent;
};

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges) {
        auto n = edges.size();
        UnionFind uf(n);
        vector<int> ans;
        vector<int> parent(n + 1);
        int conflict = -1;
        int cycle = -1;
        for (int i = 1; i < n + 1; ++i) {
            parent[i] = i;
        }

        for (int i = 0; i < n; ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            if (parent[v] != v) {
                conflict = i;
            } else {
                parent[v] = u;
                if (uf.find(u) == uf.find(v)) {
                    cycle = i;
                } else {
                    uf.unite(u, v);
                }
            }
        }

        if (conflict == -1) {
            ans = edges[cycle];
        } else {
            if (cycle == -1) {
                ans = edges[conflict];
            } else {
                ans = {parent[edges[conflict][1]], edges[conflict][1]};
            }
        }

        return ans;
    }
};

// 1 无冲突有环
// 2 有冲突有环
// 3 有冲突无环
// 关键点：a)记录冲突节点（入度>1）；b)记录第一次产生环的edge； c)记录子节点和父节点关系