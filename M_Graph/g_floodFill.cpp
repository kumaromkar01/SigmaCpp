 void dfs(vector<vector<int>> &ans, vector<vector<int>> image, int sr, int sc, int newColor){
        int n = image.size();
        int m = image[0].size();
        ans[sr][sc] = newColor;
        int inicolor = image[sr][sc]; //initialColor
        int delRow[]={-1,0,1,0};
        int delCol[] ={0,1,0,-1};
        for(int i =0;i<4;i++){
            int nrow = sr + delRow[i];
            int ncol = sc + delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==inicolor && ans[nrow][ncol]!=newColor){
                dfs(ans,image,nrow,ncol,newColor);
            }
        }
    }   
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> ans = image;
        dfs(ans,image,sr,sc,newColor);
        return ans;
    }