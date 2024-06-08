//leetcode

//memoization  beats 6%;
//TC = O(n+m) , SC = O(n+m)
class Solution {
public:
    int solve(int ind1,int ind2, string &text1, string &text2, vector<vector<int>> &dp){
        if(ind1<0 || ind2<0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        //matched
        if(text1[ind1]==text2[ind2]) {
            return dp[ind1][ind2] = 1 + solve(ind1-1,ind2-1,text1,text2,dp);
        }
        //not matched

        return dp[ind1][ind2] = max(solve(ind1,ind2-1,text1,text2,dp),solve(ind1-1,ind2,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return solve(m-1,n-1,text1,text2,dp);
    }
};

//tabulation with shift in index
//shift -1 to 0 and m to m+1
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        for(int i=0;i<=m;i++) dp[i][0] = 0;
        for(int j=0;j<=n;j++) dp[0][j] = 0;

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }

        return dp[m][n];
    }
};