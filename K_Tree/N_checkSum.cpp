 
//given an integer s , check whether a path fronm root to leaf exists having its sum to be s 
 
void check(Node* root, int &sum, int s, bool &ans){
        if (root == NULL) {
            return;
        }
        
        sum += root->data;
        // Check if it's a leaf node
        if (root->left == NULL && root->right == NULL) {
            if (sum == s) {
                ans = true;
            }
            // No matter what, backtrack the sum for this leaf node
            sum -= root->data;
            return;
        }
        
        // Traverse left and right subtrees
        check(root->left, sum, s, ans);
        check(root->right, sum, s, ans);
        
        // Backtrack the sum when moving back up in the recursive stack
        sum -= root->data;
    }
    
    bool hasPathSum(Node* root, int s) {
        if (root == NULL) {
            return false;
        }
        
        bool ans = false;
        int sum = 0;
        check(root, sum, s, ans);
        return ans;
    }