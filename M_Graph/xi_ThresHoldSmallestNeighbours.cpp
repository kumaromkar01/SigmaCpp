//problem : 
// https://www.geeksforgeeks.org/problems/city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/1


    int findCity(int n, int m, vector<vector<int>>& edges, int d) {
    // create adjacency matrix
    vector<vector<int>> adj(n,vector<int>(n,INT_MAX));
    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u][v]= wt;
        adj[v][u] = wt;
    }
    for(int i=0;i<n;i++) adj[i][i]=0;
    //floyd warshall
    for(int k =0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j =0;j<n;j++){
                if(adj[i][k]==INT_MAX || adj[k][j]==INT_MAX) continue;
                adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
    int cnt;
    int mini = INT_MAX;
    int v = -1;
    for(int i=0;i<n;i++){
        cnt=0;
        for(int j=0;j<n;j++){
            if(adj[i][j]<=d){
                cnt++;
            }
        }
        if(cnt<=mini){
            v =i;
            mini = cnt;
        }
    }

    return v;
}

//leetcode
// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>> adj(n,vector<int> (n,INT_MAX));
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u][v]=wt;
            adj[v][u]=wt;
        }
        for(int i=0;i<n;i++) adj[i][i]=0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adj[i][k]==INT_MAX || adj[k][j]==INT_MAX) continue;
                    if(adj[i][j]>adj[i][k]+adj[k][j]){
                        adj[i][j]=adj[i][k]+adj[k][j];
                    }
                }
            }
        }

        int ans = -1;
        int mini = INT_MAX;

        for(int i=0;i<n;i++){
            int cnt =0;
            for(int j=0;j<n;j++){
                if(adj[i][j]!=INT_MAX && adj[i][j]<=dt) cnt++;
            }
            if(cnt<=mini){
                mini=cnt;
                ans = i;
            }
        }
        return ans;
    }
};