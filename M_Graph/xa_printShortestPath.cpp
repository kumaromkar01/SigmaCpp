
// distance of unreachable node should be 1

// using dijkstra algorithm
class Solution
{
public:
    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        // code here
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        vector<int> dist(N, INT_MAX);
        dist[0] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty())
        {
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            for (auto it : adj[node])
            {
                int adjnode = it.first;
                int wt = it.second;

                if (dist[adjnode] > d + wt)
                {
                    dist[adjnode] = d + wt;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }
        for (int i = 0; i < N; i++)
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        return dist;
    }
};


//using topological sort
void topoSort(int node, vector<pair<int, int>> adj[],
              int vis[], stack<int> &st)
{
    // This is the function to implement Topological sort.
    vis[node] = 1;
    for (auto it : adj[node])
    {
        int v = it.first;
        if (!vis[v])
        {
            topoSort(v, adj, vis, st);
        }
    }
    st.push(node);
}
vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
{
    // code here
    vector<pair<int, int>> adj[N];
    for (int i = 0; i < M; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }
    // A visited array is created with initially
    // all the nodes marked as unvisited (0).
    int vis[N] = {
        0};
    // Now, we perform topo sort using DFS technique
    // and store the result in the stack st.
    stack<int> st;
    for (int i = 0; i < N; i++)
    {
        if (!vis[i])
        {
            topoSort(i, adj, vis, st);
        }
    }
    // Further, we declare a vector ‘dist’ in which we update the value of the nodes’
    // distance from the source vertex after relaxation of a particular node.

    vector<int> dist(N);
    for (int i = 0; i < N; i++)
    {
        dist[i] = 1e9;
    }

    dist[0] = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        for (auto it : adj[node])
        {
            int v = it.first;
            int wt = it.second;

            if (dist[node] + wt < dist[v])
            {
                dist[v] = wt + dist[node];
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (dist[i] == 1e9)
            dist[i] = -1;
    }
    return dist;
}