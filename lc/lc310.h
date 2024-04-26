#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if (n == 1) {
            return {0};
        }
        vector<int> inDegree(n, 0);
        vector<vector<int>> graph;
        graph.resize(n);
        for (auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            inDegree[edge[0]]++;
            inDegree[edge[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < inDegree.size(); ++i) {
            if (inDegree[i] == 1) {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.clear();
            auto size = q.size();
            for (int i = 0; i < size; ++i) {
                auto cur = q.front();
                q.pop();
                ans.push_back(cur);
                for (auto nextNode: graph[cur]) {
                    inDegree[nextNode]--;
                    if (inDegree[nextNode] == 1) {
                        q.push(nextNode);
                    }
                }
            }
        }
        return ans;
    }

};