#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node *cloneGraph(Node *node) {
        if (node == nullptr) {
            return nullptr;
        }
        vector<Node *> todo_list = {node};
        map<Node *, Node *> repl;

        while (!todo_list.empty()) {
            Node *todo = todo_list.back();
            todo_list.pop_back();
            if (repl.find(todo) != repl.end()) {
                continue;
            }
            Node *new_node = new Node(todo->val);
            repl[todo] = new_node;
            todo_list.insert(todo_list.end(), todo->neighbors.begin(), todo->neighbors.end());
        }

        for (auto item: repl) {
            for (auto neighbor: item.first->neighbors) {
                item.second->neighbors.push_back(repl[neighbor]);
            }
        }

        return repl[node];
    }
};