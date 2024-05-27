class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            adj[u].push_back({v,wt});
        }
        vector<int> dist(n,INT_MAX);
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{0,src}});
        dist[src]=0;

        while(!q.empty()){
            int steps = q.front().first;
            int d = q.front().second.first;
            int node = q.front().second.second;
            q.pop();
            if(steps>k) continue;
            for(auto it : adj[node]){
                int adjnode = it.first;
                int ew = it.second;

                if(dist[adjnode]>d+ew){
                    dist[adjnode]=d+ew;
                    q.push({steps+1,{d+ew,adjnode}});
                }
            }
        }
        return dist[dst]==INT_MAX?-1:dist[dst];

    }
};