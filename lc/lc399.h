#include <vector>
#include <string>
#include <map>

using namespace std;

class UnionFind {
public:
    UnionFind(vector<vector<string>> &equations, vector<double> &values) {
        for (int i = 0; i < equations.size(); ++i) {
            auto a = equations[i][0];
            auto b = equations[i][1];
            auto a_root = find(a);
            auto b_root = find(b);
            if (a_root == b_root) {
                continue;
            }
            parent[a_root] = b_root;
            times[a_root] = times[b] * values[i] / times[a];
        }
    }

    string find(string &a) {
        if (!contain(a)) {
            parent[a] = a;
            times[a] = 1.0;
            return a;
        }
        if (parent[a] != a) {
            string origin = parent[a];
            parent[a] = find(parent[a]);
            times[a] *= times[origin];
        }

        return parent[a];
    }

    bool contain(string &a) {
        return parent.find(a) != parent.end();
    }

    double getTimes(string &a, string &b) {
        if (contain(a) && contain(b) && find(a) == find(b)) {
            return times[a] / times[b];
        } else {
            return -1.0;
        }
    }

private:
    map<string, string> parent;
    map<string, double> times;
};

class Solution {
public:
    vector<double>
    calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        UnionFind uf(equations, values);
        vector<double> ans;
        for (auto query: queries) {
            auto a = query[0];
            auto b = query[1];
            ans.push_back(uf.getTimes(a, b));
        }
        return ans;
    }
};
//并查集