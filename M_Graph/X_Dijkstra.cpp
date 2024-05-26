vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V,INT_MAX);
        dist[S]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,S});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjnode = it[0];
                int edgeW = it[1];
                
                if(dist[adjnode]>dist[node]+edgeW){
                    dist[adjnode]=dist[node]+edgeW;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        return dist;
    }