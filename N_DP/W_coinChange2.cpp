
// leetcode 

//memoization
class Solution {
public:
    int solve(int ind, vector<int> &coins, int amount, vector<vector<int>> &dp){
        if(ind==0){
            return amount % coins[0]==0;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int notTake = solve(ind-1,coins,amount,dp);
        int take = 0;
        if(amount>=coins[ind]) take = solve(ind,coins,amount-coins[ind],dp);
        return dp[ind][amount] = take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return solve(n-1,coins,amount,dp);
    }
};

//tabulation
int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int am = 0;am<=amount;am++){
            if(am % coins[0]==0) dp[0][am] = 1;
        }

        for(int ind =1;ind<n;ind++){
            for(int am = 0;am<=amount;am++){
                int notTake = dp[ind-1][am];
                int take = 0;
                if(am>=coins[ind]) take = dp[ind][am-coins[ind]];
                dp[ind][am] = take+notTake;
            }
        }
        return dp[n-1][amount];
    }