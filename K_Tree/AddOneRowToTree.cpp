
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth,bool is_left=true) {
        
        
        if(depth==1)
        {
            TreeNode *newnode = new TreeNode(val);
            if(is_left)
            {
                newnode->left = root;
                newnode->right = NULL;
            }
            else
            {
                newnode->right = root;
                newnode->left = NULL;
            }
            return newnode;
        }
        
        if(root)
        {
            root->left = addOneRow(root->left,val,depth-1);
            root->right = addOneRow(root->right,val,depth-1,false);
        }
        return root;
    }
};