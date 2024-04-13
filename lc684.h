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
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        auto n = edges.size();
        UnionFind uf(n);
        vector<int> ans;
        for (auto edge: edges) {
            int a = edge[0];
            int b = edge[1];
            if (uf.find(a) != uf.find(b)) {
                uf.unite(a, b);
            } else {
                ans = edge;
            }
        }
        return ans;
    }
};