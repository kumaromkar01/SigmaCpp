//leetcode

//memoization
int solve(vector<int> &coins, int ind,int amount,vector<vector<int>> &dp){
    // you need not to worry about amount getting negative because in those case take will become 1e9 and get ignored
    // here we are using 1e9 instead of Int_max because we afraid of overflow in case of take = 1 + INT_MAX;
    if(ind==0){
        if(amount % coins[0] ==0) return amount / coins[0];
        else return 1e9;
    }
    if(dp[ind][amount]!=-1) return dp[ind][amount];
    int notTake = solve(coins,ind-1,amount,dp);
    int take  = 1e9;
    if(coins[ind]<=amount) take = 1 + solve(coins,ind,amount-coins[ind],dp);
    return dp[ind][amount] = min(take,notTake);
}
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    if(amount==0) return 0;
    vector<vector<int>> dp(n,vector<int> (amount+1,-1));
    int ans = solve(coins,n-1,amount,dp);
    return ans>=1e9?-1:ans;
}

//tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(amount==0) return 0;
        vector<vector<int>> dp(n,vector<int> (amount+1,0));
        
        for(int i=0;i<=amount;i++){
            if(i % coins[0] ==0) dp[0][i] = i / coins[0];
            else dp[0][i] = 1e9;
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<=amount;j++){
                int notTake = dp[i-1][j];
                int take  = 1e9;
                if(coins[i]<=j) take = 1 + dp[i][j-coins[i]];
                dp[i][j] = min(take,notTake);
            }
        }
        return dp[n-1][amount]>=1e9?-1:dp[n-1][amount];
    }
};

//space optimised
