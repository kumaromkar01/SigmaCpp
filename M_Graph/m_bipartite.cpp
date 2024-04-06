//gfg

    //bfs approach
    bool check(int i, int color[], vector<int> adj[]){
        //note array can't be passed in argument by applying &before it
        queue<int> q;
        q.push(i);
        color[i]=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: adj[node]){
                if(color[it]==-1){
                    color[it]=!color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]) return false;
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int color[V];
	    for(int i=0;i<V;i++) color[i]=-1;
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(check(i,color,adj)==false) return false;
	        }
	    }
	    return true;
	}

    //dfs approach
      bool check(int node, int color[],int col, vector<int> adj[],int V){
        color[node]=col;
        for(auto it: adj[node]){
            if(color[it]==-1 ){
                if(check(it,color,!col,adj,V)==false) return false;
            }
            else if(color[it]==col) return false;
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int color[V];
	    for(int i=0;i<V;i++) color[i]=-1;
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(check(i,color,0,adj,V)==false) return false;
	        }
	    }
	    return true;
	}
	