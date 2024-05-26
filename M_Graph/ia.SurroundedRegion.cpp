class Solution {
public:
    void dfs(int row,int col, vector<vector<char>> &board, vector<vector<int>> &vis){
        vis[row][col]=1;
        int m = board.size();
        int n = board[0].size();
        int delr[]={-1,0,1,0};
        int delc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr = row + delr[i];
            int nc = col + delc[i];
            if(nr>=0 && nc>=0 && nr<m && nc<n && !vis[nr][nc] && board[nr][nc]=='O'){
                dfs(nr,nc,board,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n= board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(board[i][0]=='O' && !vis[i][0]) dfs(i,0,board,vis);
            if(board[i][n-1]=='O'  && !vis[i][n-1]) dfs(i,n-1,board,vis);
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O' && !vis[0][j]) dfs(0,j,board,vis);
            if(board[m-1][j]=='O' && !vis[m-1][j]) dfs(m-1,j,board,vis); 
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
        return ;
    }
};