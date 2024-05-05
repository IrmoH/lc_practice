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
    void preorderTraversal(TreeNode *root, vector<int> *order) {
        if(root== nullptr){
            return;
        }
        order->push_back(root->val);
        preorderTraversal(root->left, order);
        preorderTraversal(root->right, order);
    }
    void inorderTraversal(TreeNode *root, vector<int> *order) {
        if(root== nullptr){
            return;
        }
        inorderTraversal(root->left, order);
        order->push_back(root->val);
        inorderTraversal(root->right, order);
    }
    void postorderTraversal(TreeNode *root, vector<int> *order) {
        if(root== nullptr){
            return;
        }
        postorderTraversal(root->left, order);
        postorderTraversal(root->right, order);
        order->push_back(root->val);
    }


    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> order;
        preorderTraversal(root, &order);
        return  order;
    }
};
//二叉树遍历：前序、中序、后序