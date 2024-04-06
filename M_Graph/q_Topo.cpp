//kahn's algorithm 
//gfg

vector<int> topoSort(int v, vector<int> adj[]) 
{
    // code here
    vector<int> indeg(v,0);
    for(int i=0;i<v;i++){
        for(auto it: adj[i]){
            indeg[it]++;
        }
    }
    
    queue<int> q;
    for(int i=0;i<v;i++){
        if(indeg[i]==0) q.push(i);
    }
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it: adj[node]){
            indeg[it]--;
            if(indeg[it]==0) q.push(it);
        }
        
    }
    return topo;
	   
}

//dfs approach 

	void dfs(int node,stack<int> &st,int vis[],vector<int> adj[]){
	    vis[node]=1;
	    for(auto it : adj[node]){
	        if(!vis[it]) dfs(it,st,vis,adj);
	    }
	    st.push(node);
	    return;
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int v, vector<int> adj[]) 
	{
	    // code here
	    //you just need to maintain a stack such that when you are returning from dfs
	    //you have to push it in that stack.
	    
	    int vis[v]={0};
	    stack<int> st;
	    for(int i=0;i<v;i++){
	        if(!vis[i]) dfs(i,st,vis,adj);
	    }
	    
	    vector<int> ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	   return ans;
	}
