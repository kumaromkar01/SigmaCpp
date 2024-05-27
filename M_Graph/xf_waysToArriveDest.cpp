class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // create adjacency list
        vector<pair<int,int>> adj[n];
        for(int i=0; i<roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        // Use long long for distance and pq will have distance and node
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0); //number of ways to reach a node with given distance
        dist[0] = 0;
        ways[0] = 1;
        int MOD = (int)(1e9 + 7);
        pq.push({0, 0});
        
        while(!pq.empty()){
            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjnode = it.first;
                long long wt = it.second;

                if(d + wt < dist[adjnode]){
                    dist[adjnode] = d + wt;
                    ways[adjnode] = ways[node];
                    pq.push({d + wt, adjnode});
                } else if(d + wt == dist[adjnode]){
                    ways[adjnode] = (ways[adjnode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n-1] % MOD;

    }
};