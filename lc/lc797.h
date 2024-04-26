#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> track;

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        dfs(graph, 0);
        return res;
    }

    void dfs(vector<vector<int>> &graph, int node) {
        track.push_back(node);
        if (node == graph.size() - 1) {
            res.push_back(track);
        }

        auto path = graph[node];
        for (int i = 0; i < path.size(); ++i) {
            dfs(graph, path[i]);
        }
        track.pop_back();
    }
};