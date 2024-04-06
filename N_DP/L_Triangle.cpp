

//recursion
class Solution {
public:
    int sum(int i,int j, vector<vector<int>>&triangle, int n){
        if(i==n-1) return triangle[i][j];
        //it can't go out of the boundary
        int down = triangle[i][j]+sum(i+1,j,triangle,n);
        int diagonal  = triangle[i][j]+sum(i+1,j+1,triangle,n);
        return min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        return sum(0,0,triangle,n);
    }
};
//memoization
class Solution {
public:
    int sum(int i,int j, vector<vector<int>>&triangle, int n,vector<vector<int>> &dp){
        if(i==n-1) return dp[i][j]=triangle[i][j];
        //it can't go out of the boundary
        if(dp[i][j]!=-1) return dp[i][j];
        int down = triangle[i][j]+sum(i+1,j,triangle,n,dp);
        int diagonal  = triangle[i][j]+sum(i+1,j+1,triangle,n,dp);
        return dp[i][j]=min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return sum(0,0,triangle,n,dp);
    }
};
//tabulation
class Solution {
public:
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n));
        //base ready
        for(int i =0;i<n;i++) dp[n-1][i] = triangle[n-1][i];

        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down,diagonal);
            }
        }

        return dp[0][0];
    }
};
// space optimisation
