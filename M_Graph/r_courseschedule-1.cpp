class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& p) {
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
        int cnt = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            for (auto it : adj[node]) {
                indeg[it]--;
                if (indeg[it] == 0) {
                    q.push(it);
                }
            }
        }
        // Corrected: If cnt is less than v, there is a cycle.
        if (cnt < v) {
            return false;
        }
        return true;
    }
};