#include <vector>
#include <string>

using namespace std;

class UnionFind {
public:
    UnionFind() {
        parent.resize(26);
        for (int i = 0; i < 26; ++i) {
            parent[i] = i;
        }
    }

    void unite(int x, int y) {
        parent[find(x)] = find(y);
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }

private:
    vector<int> parent;
};

class Solution {
public:
    bool equationsPossible(vector<string> &equations) {
        UnionFind uf;
        for (auto equation: equations) {
            if (equation[1] == '=') {
                auto x = equation[0] - 'a';
                auto y = equation[3] - 'a';
                uf.unite(x, y);
            }
        }
        for (auto equation: equations) {
            if (equation[1] == '!') {
                auto x = equation[0] - 'a';
                auto y = equation[3] - 'a';
                if (uf.find(x) == uf.find(y)) {
                    return false;
                }
            }
        }
        return true;
    }
};