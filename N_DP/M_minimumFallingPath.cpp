

//recursion
class Solution {
public:
    int f(int i,int j, vector<vector<int>> &matrix){
        if(j<0 || j>=matrix[0].size()) return 1e9;
        if(i==0) return matrix[0][j];

        int u= matrix[i][j]+f(i-1,j,matrix);
        int dl = matrix[i][j]+f(i-1,j-1,matrix);
        int dr = matrix[i][j] + f(i-1,j+1,matrix);
        return min(u,min(dl,dr));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n = matrix[0].size();
        int mini = 1e9;
        for(int j=0;j<n;j++){
            mini = min(mini,f(m-1,j,matrix));
        }
        return mini;
    }
};
//memoization
class Solution {
public:
    int f(int i,int j, vector<vector<int>> &matrix, vector<vector<int>> &dp){
        if(j<0 || j>=matrix[0].size()) return 1e9;
        if(i==0) return dp[0][j]=matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int u= matrix[i][j]+f(i-1,j,matrix,dp);
        int dl = matrix[i][j]+f(i-1,j-1,matrix,dp);
        int dr = matrix[i][j] + f(i-1,j+1,matrix,dp);
        return dp[i][j]=min(u,min(dl,dr));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n = matrix[0].size();
        int mini = 1e9;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int j=0;j<n;j++){
            mini = min(mini,f(m-1,j,matrix,dp));
        }
        return mini;
    }
};
//tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int mini = 1e9;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int u = 1e9, dl = 1e9, dr = 1e9;
                u = matrix[i][j] + dp[i - 1][j];
                if (j - 1 >= 0) {
                    dl = matrix[i][j] + dp[i - 1][j - 1];
                }
                if (j + 1 < n) {
                    dr = matrix[i][j] + dp[i - 1][j + 1];
                }
                dp[i][j] = min(u, min(dl, dr));
            }
        }
        for (int j = 0; j < n; j++) {
            mini = min(mini, dp[m - 1][j]);
        }
        return mini;
    }
};