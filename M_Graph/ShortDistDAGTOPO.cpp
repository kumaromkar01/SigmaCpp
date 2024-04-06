void toposort(int node, vector<pair<int, int>> adj[], int vis[], stack<int> &st) {
        vis[node] = 1;
        for (auto it : adj[node]) {
            int v = it.first;
            if (!vis[v]) toposort(v, adj, vis, st);
        }
        st.push(node);
    }
    
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        vector<pair<int, int>> adj[N];
        
        // Build adjacency list
        for (int i = 0; i < M; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
    
        // Find topoSort;
        int vis[N] = {0};
        stack<int> st;
        vector<int> dist(N, -1);  // Initialize distances with -1
    
        // Find topological order
        for (int i = 0; i < N; i++) {
            if (!vis[i]) toposort(i, adj, vis, st);
        }
    
        // Distance updation
        dist[0] = 0;
    
        while (!st.empty()) {
            int node = st.top();
            st.pop();
            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;
                if (dist[node] != -1 && (dist[v] == -1 || dist[node] + wt < dist[v])) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
    
        return dist;
    }