//gfg

void bfs(int srow, int scol, vector<vector<int>> &vis, vector<vector<char>> &grid) {
        vis[srow][scol] = 1;
        queue<pair<int, int>> q;
        q.push({srow, scol});
        int n = grid.size();
        int m = grid[0].size();
        while (!q.empty()) {
            int crow = q.front().first;
            int ccol = q.front().second;
            q.pop();
    
            for (int drow = -1; drow <= 1; drow++) {
                for (int dcol = -1; dcol <= 1; dcol++) {
                    int nrow = crow + drow;
                    int ncol = ccol + dcol;
                    bool valid = ncol >= 0 && ncol < m && nrow >= 0 && nrow < n;
                    bool isLand = valid && grid[nrow][ncol] == '1';
                    if (valid && !vis[nrow][ncol] && isLand) {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(); // number of rows in adj matrix
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt =0;
        for(int i = 0;i<n;i++){
            for(int j  =0 ;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
        
    }



    // leetcode : if diagonal is exempted 
class Solution {
public:
    void bfs(int srow, int scol, vector<vector<int>> &vis, vector<vector<char>> &grid) {
        vis[srow][scol] = 1;
        queue<pair<int, int>> q;
        q.push({srow, scol});
        int n = grid.size();
        int m = grid[0].size();
        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        while (!q.empty()) {
            int crow = q.front().first;
            int ccol = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nrow = crow + drow[k];
                int ncol = ccol + dcol[k];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }


    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size(); // number of rows in adj matrix
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt =0;
        for(int i = 0;i<n;i++){
            for(int j  =0 ;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
        
    }
};
