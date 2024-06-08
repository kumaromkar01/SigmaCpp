//gfg
//https://www.geeksforgeeks.org/problems/rod-cutting0840/1

//memoization
int solve(int ind,int price[],int n,vector<vector<int>> &dp){
    if(ind==0){
        return  price[0] * n ;
    }
    if(dp[ind][n]!=-1) return dp[ind][n];
    int notTake = solve(ind-1,price,n,dp);
    int take = INT_MIN;
    if(n>ind) take = price[ind] + solve(ind,price,n-ind-1,dp);
    return dp[ind][n] = max(take,notTake);
}
int cutRod(int price[], int n) {
    //code here
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return solve(n-1,price,n,dp);
    
}

//tabulation
int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            dp[0][i] = price[0] * i;
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int notTake = dp[i-1][j];
                int take = INT_MIN;
                if(j>i) take = price[i] +dp[i][j-i-1];
                dp[i][j] = max(take,notTake);
            }
        }
        return dp[n-1][n];
        
    }