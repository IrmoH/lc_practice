#include <vector>
#include <map>
#include <algorithm>

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
    int max_diameter_ = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);
        return max_diameter_;
    }


    int maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int left_depth = maxDepth(root->left);
        int right_depth = maxDepth(root->right);

        max_diameter_ = max(max_diameter_, left_depth+ right_depth);

        return max(left_depth, right_depth) + 1;
    }
};