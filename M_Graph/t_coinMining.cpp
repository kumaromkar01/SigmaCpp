    //gfg contest 140
    
    void dfs(int i, int j, vector<vector<int>> &vis, int &sum, vector<vector<int>> &grid, int N, int &maxi) {
        vis[i][j] = 1;
        sum += grid[i][j];
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
    
        for (int k = 0; k < 4; k++) {
            int ir = i + delrow[k];
            int ic = j + delcol[k];
            if (ir >= 0 && ir < N && ic >= 0 && ic < N && !vis[ir][ic] && grid[ir][ic] != 0) {
                dfs(ir, ic, vis, sum, grid, N, maxi);
                sum -= grid[ir][ic];
            }
        }
    
        maxi = max(maxi, sum);
        vis[i][j]=0;
    }
    
    int maximumCoins(int N, vector<vector<int>> &grid) {
        vector<vector<int>> vis(N, vector<int>(N, 0));
        int sum = 0;
        int maxi = INT_MIN;
    
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if ((i + j) % 2 == 1 && !vis[i][j] && grid[i][j] != 0) {
                    sum = 0;
                    dfs(i, j, vis, sum, grid, N, maxi);
                }
            }
        }
    
        return maxi==INT_MIN?0:maxi;
    }