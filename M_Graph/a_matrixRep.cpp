

//coding ninjas 
vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
    // Write your code here.
    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++){
        adj[i].push_back(i);
    }
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    return adj;

}