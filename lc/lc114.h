#include "tree_node.h"
#include <vector>

using namespace std;

class Solution {
public:
    void flatten(TreeNode *root) {
        if (root == nullptr) {
            return;
        }

        flatten(root->left);
        flatten(root->right);

        auto left = root->left;
        auto right = root->right;

        root->left = nullptr;
        root->right = left;

        TreeNode *p = root;
        while (p->right != nullptr) {
            p = p->right;
        }
        p->right = right;
    }
};
