//find the distance of nearest 0 cell
// on gfg : another name

//leetcode

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(!vis[i][j] && mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;
            ans[row][col] = step;
            q.pop();
            int delRow[] = {-1,0,1,0};
            int delCol[] = {0,1,0,-1};
            for(int i =0;i<4;i++){
                int ir = row + delRow[i];
                int ic = col + delCol[i];
                if(ir>=0 && ir<n && ic>=0 && ic<m && vis[ir][ic]==0 && mat[ir][ic]==1){
                    q.push({{ir,ic},step+1});
                    vis[ir][ic]=1;
                }
            }
        }
        return ans;
    }
};