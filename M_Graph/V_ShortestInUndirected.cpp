vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> adj[N];
        for(int i=0;i<M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> dist(N,1e9);
        queue<int> q;
        q.push(src);
        dist[src]=0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(int it : adj[node]){
                if(dist[it]>dist[node]+1){
                    dist[it]=dist[node]+1;
                    q.push(it);
                }
            }
        }
        
        for(int i=0;i<N;i++){
            if(dist[i]==1e9) dist[i]=-1;
        }
        return dist;
    }