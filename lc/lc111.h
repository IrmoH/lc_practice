#include <vector>
#include <queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (root== nullptr){
            return 0;
        }
        queue<TreeNode *> q;
        q.push(root);

        int depth = 1;
        while (!q.empty()) {
            auto size = q.size();
            for (int i = 0; i < size; ++i) {
                auto cur = q.front();
                q.pop();
                if (cur->left == nullptr && cur->right == nullptr) {
                    return depth;
                }
                if (cur->left != nullptr) {
                    q.push(cur->left);
                }
                if (cur->right != nullptr) {
                    q.push(cur->right);
                }
            }
            depth++;
        }
        return depth;
    }
};
//二叉树层序遍历：求最小深度