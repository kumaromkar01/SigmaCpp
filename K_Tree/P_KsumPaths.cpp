class Solution {
public:
    void countPaths(Node* root, int target, int currSum, unordered_map<int, int>& pathSum, int& count) {
        if (!root) return;

        currSum += root->data;

        // If the current sum equals the target, increment count
        if (currSum == target) count++;

        // If the difference (currSum - target) exists in the pathSum map,
        // increment count by the number of occurrences of (currSum - target)
        if (pathSum.find(currSum - target) != pathSum.end()) {
            count += pathSum[currSum - target];
        }

        // Increment the count of current sum in the pathSum map
        pathSum[currSum]++;

        // Recurse for left and right subtrees
        countPaths(root->left, target, currSum, pathSum, count);
        countPaths(root->right, target, currSum, pathSum, count);

        // Decrement the count of current sum in the pathSum map as the recursion backtracks
        pathSum[currSum]--;
    }

    int sumK(Node* root, int k) {
        unordered_map<int, int> pathSum; // Map to store running sums
        int count = 0;
        countPaths(root, k, 0, pathSum, count);
        return count;
    }
};