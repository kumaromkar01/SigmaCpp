   bool dfs(int node,int parent,vector<vector<int>> &adj,int vis[]){
       vis[node]=1;
       for(auto it: adj[node]){
           if(!vis[it]){
               if(dfs(it,node,adj,vis)==true) return true;
           } 
           else if(it!=parent) return true;
       }
       return false;
      
   }
    int isTree(int n, int m, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(n); //adjacency list
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int vis[n]={0}; //visited array
        if(dfs(0,-1,adj,vis)==true) return false; //
        for(int i=0;i<n;i++){
            if(!vis[i]) { //if there are different components it is not a tree
                return false;
            }
        }
        return true;
    }