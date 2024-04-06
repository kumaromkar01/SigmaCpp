//leetcode solution of level order traversal of binary tree

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size(); // Get the number of nodes at this level
            vector<int> levelNodes;

            // Traverse nodes at this level
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                levelNodes.push_back(node->val);

                // Enqueue children of the current node
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            ans.push_back(levelNodes);
        }

        return ans;
    }
};