//recursion  O(2^(m*n))
class Solution {
public:
    int solve(int i,int j, vector<vector<int>>& obs){
        if(i==0 && j==0) return 1;
        if(i>=0 && j>=0 && obs[i][j]==1) return 0;
        if(i<0 || j<0) return 0;
        int up = solve(i-1,j,obs);
        int left = solve(i,j-1,obs);
        return up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m= obs.size();
        int n = obs[0].size();
        return solve(m-1,n-1,obs);
    }
};

//memoisation
class Solution {
public:
    int solve(int i,int j, vector<vector<int>>& obs,  vector<vector<int>> &dp){
        if(i==0 && j==0) return 1;
        if(i>=0 && j>=0 && obs[i][j]==1) return 0;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = solve(i-1,j,obs,dp);
        int left = solve(i,j-1,obs,dp);
        return dp[i][j]=up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m= obs.size();
        int n = obs[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,obs,dp);
    }
};

// tabulation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m= obs.size();
        int n = obs[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obs[i][j]==1) dp[i][j]=0;
                else if(i==0 && j==0) dp[i][j]=1;
                else {
                    int up =0,left =0;
                    if(i>=1) up=dp[i-1][j];
                    if(j>=1) left = dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};

//space optimisation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m= obs.size();
        int n = obs[0].size();
        vector<int>prev (n,0);
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(obs[i][j]==1) curr[j]=0;
                else if(i==0 && j==0) curr[j]=1;
                else {
                    int up =0,left =0;
                    if(i>=1) up=prev[j];
                    if(j>=1) left = curr[j-1];
                    curr[j]=up+left;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};