/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        vector<TreeNode*> nodes;
        preorder(root, nodes);
        for (int i = 1; i < nodes.size(); ++i) {
            root->left = nullptr;
            root->right = nodes[i];
            root = root->right;
        }
    }

    void preorder(TreeNode* root, vector<TreeNode*>& nodes) {
        if (root == nullptr) return;

        nodes.push_back(root);
        preorder(root->left, nodes);
        preorder(root->right, nodes);
    }
};
