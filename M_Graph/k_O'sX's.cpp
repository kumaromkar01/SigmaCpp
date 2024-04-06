//O'sX's in gfg
    #include<bits/stdc++.h>
    //dfs approach
    void dfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>> &mat){
        //note that passing by refrence reduces time as it avoids unnecessary copying
        int n = mat.size();
        int m = mat[0].size();
        vis[row][col]=1;
        int dR[]={-1,0,1,0};
        int dC[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int ir = row + dR[i];
            int ic = col + dC[i];
            if(ir>=0 && ir<n && ic>=0 && ic<m && !vis[ir][ic] && mat[ir][ic]=='O'){
                dfs(ir,ic,vis,mat);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n,vector<int>(m,0));
        //ist col && last col
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O' && !vis[i][0]) dfs(i,0,vis,mat);
            if(mat[i][m-1]=='O' && !vis[i][m-1]) dfs(i,m-1,vis,mat);
        }
        //ist row and ist col
        for(int j=0;j<m;j++){
            if(mat[0][j]=='O' && !vis[0][j]) dfs(0,j,vis,mat);
            if(mat[n-1][j]=='O' && !vis[n-1][j]) dfs(n-1,j,vis,mat); 
        }
        
        
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(mat[i][j]=='O' && !vis[i][j]) mat[i][j]='X';
            }
        }
        
      return mat;
        
    }

    //bfs approach
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(!vis[i][0] && mat[i][0]=='O'){ q.push({i,0}); vis[i][0]=1;}
            if(!vis[i][m-1] && mat[i][m-1]=='O'){ q.push({i,m-1}); vis[i][m-1]=1;}
        }
        
        for(int j=0;j<m;j++){
            if(!vis[0][j] && mat[0][j]=='O'){ q.push({0,j}); vis[0][j]=1;}
            if(!vis[n-1][j] && mat[n-1][j]=='O'){ q.push({n-1,j}); vis[n-1][j]=1;}
        }
        
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int dR[]={-1,0,1,0};
            int dC[]={0,1,0,-1};
            for(int i=0;i<4;i++){
                int ir = row + dR[i];
                int ic = col + dC[i];
                if(ir>=0 && ir<n && ic>=0 && ic<m && !vis[ir][ic] && mat[ir][ic]=='O'){
                    q.push({ir,ic});
                    vis[ir][ic]=1;
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(mat[i][j]=='O' && !vis[i][j]) mat[i][j]='X';
            }
        }
        
      return mat;
        
    }

