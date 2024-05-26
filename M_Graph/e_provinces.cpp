//gfg number of connected components and number of islands

void dfs(vector<int> arr[],vector<int>&vis,int node){
        vis[node]=1;
        for(auto i: arr[node]){
            if(!vis[i]) dfs(arr,vis,i);
        }
    }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        //create adj list from adj matrix
        vector<int> arr[V];
        for(int i =0;i<V;i++){
            for(int j =0;j<V;j++){
                if(adj[i][j]==1 && i!=j){
                    arr[i].push_back(j);
                    arr[j].push_back(i);
                }
            }
        }
        int cnt =0;
        vector<int> vis(V,0);
        
        //agar dfs me kuch vis nhi hua toh aage vis karane keliye loop
        for(int i =0; i< V;i++){
            if(!vis[i]){
                //dfs visit nhi kar paya ek start node se mtlb disconnected tha
                //fir se start node consider kro
                dfs(arr,vis,i);
                cnt++;
            }
        }
        return cnt;
    }

//