//dfs approach

    bool dfs(int node,int vis[],int pathVis[],vector<int> adj[]){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it : adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,pathVis,adj)==true) return true;
            }
            else if(pathVis[it]==1 && vis[it]==1 ) return true;
        }
        pathVis[node]=0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        int pathVis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,vis,pathVis,adj)==true) return true;
            }
        }
        return false;
    }



//bfs approach using topological sort
  bool isCyclic(int v, vector<int> adj[]) {
        // code here
        int indeg[v]={0};
        for(int i=0;i<v;i++){
            for(auto it: adj[i]){
                indeg[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<v;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        int cnt =0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it: adj[node]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }
        if(cnt==v) return false;
        return true;
    }
    
