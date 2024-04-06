
// LeetCode Validate binary Search Tree


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
    bool isBst(TreeNode* root, long long int min,long long int max){
        if(root==NULL) return true;
        
        if(root->val>min&&root->val<max){
            bool leftAns= isBst(root->left,min,root->val);
            bool rightAns = isBst(root->right,root->val,max);
            return leftAns&&rightAns;
        }
            return false;
        
    }
    bool isValidBST(TreeNode* root) {
        if(root->left==NULL&&root->right==NULL) return true;
        return isBst(root, LLONG_MIN,LLONG_MAX);
    }
};