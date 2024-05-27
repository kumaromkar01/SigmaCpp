class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<times.size();i++){
            int u= times[i][0];
            int v= times[i][1];
            int wt = times[i][2];
            adj[u].push_back({v,wt});
        }
        vector<int> time(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> >pq;
        pq.push({0,k});
        time[k]=0;

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                int adjnode = it.first;
                int t = it.second;
                if(d+t< time[adjnode]){
                    pq.push({d+t,adjnode});
                    time[adjnode]=d+t;
                }
                
            }
        }
        int maxi = INT_MIN;
        for(int i=1;i<n+1;i++){
            if(time[i]==INT_MAX) return -1;
            maxi = max(maxi,time[i]);
        }
        return maxi;
    }
};