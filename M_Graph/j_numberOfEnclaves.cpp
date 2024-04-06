
// solution using dfs memory limit exceedes in 57/58 if using delRow,delCol and vis array in int
class Solution {
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int &n,int &m,int row,int col){
        visited[row][col]=1;

        int del[]={0,1,0,-1,0};

        for(int i=0;i<4;i++){
            int nRow=row+del[i];
            int nCol=col+del[i+1];

            if(nRow>=0&&nCol>=0&&nRow<n&&nCol<m&&!visited[nRow][nCol]&&grid[nRow][nCol]==1){
                dfs(grid,visited,n,m,nRow,nCol);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,0));

        for(int i=0;i<n;i++){
            if(!visited[i][0]&&grid[i][0]) dfs(grid,visited,n,m,i,0);

            if(!visited[i][m-1]&&grid[i][m-1]) dfs(grid,visited,n,m,i,m-1);
        }

        for(int i=1;i<m-1;i++){
            if(!visited[0][i]&&grid[0][i]) dfs(grid,visited,n,m,0,i);

            if(!visited[n-1][i]&&grid[n-1][i]) dfs(grid,visited,n,m,n-1,i);
        }

        int lands=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]&&!visited[i][j]) lands++;
            }
        }

        return lands;

    }
};

//using bfs

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        queue<pair<int,int>> q;
        //first and last row
       for(int i=0;i<n;i++){
           for(int j =0;j<m;j++){
               if(i==0 || i==n-1 || j==0 || j==m-1){
                   if(grid[i][j]==1)
                   q.push({i,j});
                   vis[i][j]=1;
               }
           }
       }

       while(!q.empty()){
           int row = q.front().first;
           int col = q.front().second;
           q.pop();

           int delRow[] = {-1,0,1,0};
           int delCol[] = {0,-1,0,1};

           for(int i =0;i<4;i++){
               int ir = row + delRow[i];
               int ic = col + delCol[i];

               if(ir>=0 && ir<n && ic>=0 && ic<m && !vis[ir][ic] && grid[ir][ic]==1){
                   q.push({ir,ic});
                   vis[ir][ic] =1;
               }
           }
       }
        int cnt =0;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==1){
                    if(vis[i][j]==0) cnt++;
                }
            }
        }
        return cnt;

    }
};