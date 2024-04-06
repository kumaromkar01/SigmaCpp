

class Solution {
public:
    vector<int> topView(Node *root) {
        vector<int> ans;  //to store data of nodes in top view
        if (root == NULL) return ans;
        map<int, int> topNode;  //to store nodes in top view in map of hd and data
        queue<pair<Node*, int>> q; // queue to push nodes with horizontal depth
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            pair<Node*, int> temp = q.front();
            Node* frontNode = temp.first;
            int hd = temp.second;
            
            if (topNode.find(hd) == topNode.end()) { //if there exists no node of that hd, insert
                topNode[hd] = frontNode->data;
            }
            
            if (frontNode->left) {
                q.push(make_pair(frontNode->left, hd - 1));
            }
            
            if (frontNode->right) {
                q.push(make_pair(frontNode->right, hd + 1));
            }
            
            q.pop();
        }
        
        for (auto i : topNode) {
            ans.push_back(i.second);
        }
        
        return ans;
    }
};
