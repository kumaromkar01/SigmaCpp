// khud se banaya hua code
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        queue<pair<int,int>> q;
        if(grid[0][0]==1 || grid[m-1][n-1]==1) return -1;
        q.push({0,0});
        dist[0][0]=1;

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();

            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nx = x+i;
                    int ny = y+j;

                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==0){
                        if(dist[nx][ny]>dist[x][y]+1){
                            q.push({nx,ny});
                            dist[nx][ny]=dist[x][y]+1;
                        }
                    }
                }
            }
        }
        return dist[m-1][n-1]==INT_MAX?-1:dist[m-1][n-1];
    }
};

//striver wala code
