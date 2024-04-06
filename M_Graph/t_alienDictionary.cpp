   vector<int> toposort(int V,vector<int>adj[]){
        int indeg[V]={0};
        for(int i=0;i<V;i++){
            for(auto it: adj[i]){
                indeg[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<V;i++){
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
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        for(int i=0;i<N-1;i++){
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(),s2.size());
            for(int j=0;j<len;j++){
                if(s1[j]!=s2[j]){
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    break;
                }
            }
        }
        vector<int> topo = toposort(K,adj);
        string ans ="";
        for(auto it : topo){
            ans+=char(it+'a');
        }
        return ans;
    }