//dfs 

bool dfs(int node,vector<int> adj[],int vis[],int pathVis[], int check[]){
        vis[node]=1;
        pathVis[node]=1;
        check[node]=0;
        for(auto it: adj[node]){
            if(!vis[it]){
                if(dfs(it,adj,vis,pathVis,check)==true) {
                    check[node]=0;
                    return true;
                }
                
            }
            else if(pathVis[it]){
                check[node]=0;
                return true;
            }
        }
        check[node]=1;
        pathVis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        // code here
        int vis[v]={0};
        int pathvis[v]={0};
        int check[v]={0};
        vector<int> safeNodes;
        for(int i=0;i<v;i++){
            if(!vis[i]){
                dfs(i,adj,vis,pathvis,check);
            } 
        }
        for(int i=0;i<v;i++){
            if(check[i]==1) safeNodes.push_back(i);
        }
        return safeNodes;
        
    }


//topological sort approach

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> adjRev[v];
        vector<int> indeg(v,0);

        for(int i=0;i<v;i++){
            for(auto it: graph[i]){
                adjRev[it].push_back(i);
                indeg[i]++;
            }
        }

        queue<int> q;
        vector<int> safe;
        for(int i=0;i<v;i++){
            if(indeg[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe.push_back(node);
            for(auto it: adjRev[node]){
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }

        sort(safe.begin(),safe.end());
        return safe;

    }
};