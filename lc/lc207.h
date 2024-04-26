#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        auto graph = buildGraph(numCourses, prerequisites);
        vector<int> inDegree(numCourses, 0);
        for (auto prerequisite: prerequisites) {
            inDegree[prerequisite[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < inDegree.size(); ++i) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty()) {
            auto cur_node = q.front();
            q.pop();
            count++;
            for (auto nextNode: graph[cur_node]) {
                inDegree[nextNode]--;
                if (inDegree[nextNode] == 0) {
                    q.push(nextNode);
                }
            }

        }
        return count == numCourses;
    }

    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>> &prerequisites) {
        vector<vector<int>> graph;
        graph.resize(numCourses);
        for (auto prerequisite: prerequisites) {
            graph[prerequisite[1]].push_back(prerequisite[0]);
        }
        return graph;
    }
};