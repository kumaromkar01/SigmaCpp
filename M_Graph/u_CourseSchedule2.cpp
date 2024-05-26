class Solution {
public:
    vector<int> findOrder(int v, vector<vector<int>>& p) {
        vector<int> adj[v];
        for(auto it: p){
            adj[it[1]].push_back(it[0]);
        }
        vector<int> indeg(v, 0);
        for (int i = 0; i < v; i++) {
            for (auto it : adj[i]) {
                indeg[it]++;
            }
        }
    
        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
    
        vector<int> result;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);
    
            for (auto it : adj[node]) {
                indeg[it]--;
                if (indeg[it] == 0) {
                    q.push(it);
                }
            }
        }
    
        // Check for a cycle
        if (result.size() != v) {
            // If result size is less than v, there is a cycle.
            return {};  // Return an empty vector to indicate a cycle.
        }
    
        return result;
    }
};