

// Given a m x n grid filled with non-negative numbers, 
// find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

//recursion
class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &grid){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return 1e9;

        int up = grid[i][j]+solve(i-1,j,grid);
        int left = grid[i][j]+solve(i,j-1,grid);
        return min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return solve(m-1,n-1,grid);
    }
};
//memoization O(mn)  && s.c O(n*m)+O(n-1)(m-1)
class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &grid,vector<vector<int>> &dp){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = grid[i][j]+solve(i-1,j,grid,dp);
        int left = grid[i][j]+solve(i,j-1,grid,dp);
        return dp[i][j]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,grid,dp);
    }
};

//tabulation  
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i =0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j]=grid[0][0];
                else {
                    int up=1e9,left = 1e9;
                    if(i>0) up=grid[i][j]+dp[i-1][j];
                    if(j>0) left=grid[i][j]+dp[i][j-1];
                    dp[i][j]=min(up,left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};
//space optimisation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> prev(n);
        for(int i =0;i<m;i++){
            vector<int> curr(n);
            for(int j=0;j<n;j++){
                if(i==0 && j==0) curr[j]=grid[0][0];
                else {
                    int up=1e9,left = 1e9;
                    if(i>0) up=grid[i][j]+prev[j];
                    if(j>0) left=grid[i][j]+curr[j-1];
                    curr[j]=min(up,left);
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};