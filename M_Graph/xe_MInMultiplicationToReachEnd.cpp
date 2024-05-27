int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<int> dist(100000,1e9);
        queue<pair<int,int>> q;
        dist[start]=0;
        q.push({start,0});
        int mod = 100000;
        while(!q.empty()){
            int node = q.front().first;
            int d = q.front().second;
            if(node==end) return d;
            q.pop();
            for(int it : arr){
                int num = (it*node)%mod;
                if(dist[num]>d+1){
                    dist[num]=d+1;    
                    q.push({num,d+1});
                }
            }
        }
        return -1;
    }