    bool bfs(int src,int vis[],vector<int> adj[]){
       vis[src]=1;
       queue<pair<int,int>> q; //node,paremt
       q.push({src,-1});
       while(!q.empty()){
           int node = q.front().first;
           int parent = q.front().second;
           q.pop();
           for(auto it: adj[node]){
               if(!vis[it]){
                   vis[it]=1;
                   q.push({it,node});
               }
               else if(vis[it] && it!=parent) return true;
           }
       }
       return false;
   }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        int vis[v]={0};
        for(int i=0;i<v;i++){
            if(!vis[i]) {
                if(bfs(i,vis,adj)==true) return true;
            }
        }
        return false;
    }


    //dfs approach
    bool dfs(int src,int parent,int vis[],vector<int> adj[]){
       vis[src]=1;
       for(auto it: adj[src]){
           if(!vis[it]){
               if(dfs(it,src,vis,adj)==true) return true;
           }
           else if(it != parent) return true;
       }
       return false;
   }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
        // Code here
        int vis[v]={0};
        for(int i=0;i<v;i++){
            if(!vis[i]) {
                if(dfs(i,-1,vis,adj)==true) return true;
            }
        }
        return false;
    }