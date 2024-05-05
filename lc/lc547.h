#include <vector>

using namespace std;

class UnionFind {
public:
    UnionFind(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
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

    int getProvinces() {
        int provinces = 0;
        for (int i = 0; i < parent.size(); ++i) {
            if (parent[i] == i) {
                provinces++;
            }
        }
        return provinces;
    }

private:
    vector<int> parent;
};

class Solution {
public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int cites = isConnected.size();
        UnionFind uf(cites);
        for (int i = 0; i < cites; ++i) {
            for (int j = i + 1; j < cites; ++j) {
                if (isConnected[i][j]) {
                    uf.unite(i, j);
                }
            }
        }
        return uf.getProvinces();
    }
};
//并查集