#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        auto graph = buildGraph(numCourses, prerequisites);
        vector<int> inDegree(numCourses, 0);
        for (auto edge: prerequisites) {
            inDegree[edge[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < inDegree.size(); ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> order;
        while (!q.empty()) {
            auto cur_node = q.front();
            q.pop();
            order.push_back(cur_node);
            for (auto nextNode: graph[cur_node]) {
                inDegree[nextNode]--;
                if (inDegree[nextNode] == 0) {
                    q.push(nextNode);
                }
            }

        }
        if (order.size() != numCourses) {
            return {};
        }
        return order;
    }

    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> graph;
        graph.resize(numCourses);
        for (auto edge: prerequisites) {
            graph[edge[1]].push_back(edge[0]);
        }
        return graph;
    }
};