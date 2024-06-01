// gfg https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

//memoization
int solve(int ind, int val[],int wt[], int w,vector<vector<int>> &dp){
    if(w==0) return 0;
    if(ind==0) return wt[0]<=w?val[0]:0;
    if(dp[ind][w]!=-1) return dp[ind][w];
    int nottake = solve(ind-1,val,wt,w,dp);
    int take = 0;
    if(wt[ind]<=w) take = val[ind] + solve(ind-1,val,wt,w-wt[ind],dp);
    return dp[ind][w] = max(take,nottake);
}
int knapSack(int W, int wt[], int val[], int n) 
{ 
    // Your code here
    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    return solve(n-1,val,wt,W,dp);
}

//tabulation
int knapSack(int w, int wt[], int val[], int n) 
{ 
    // Your code here
    vector<vector<int>> dp(n,vector<int>(w+1,0));
    for(int i = wt[0];i<=w;i++) dp[0][i] = val[0];
    
    for(int i=1;i<n;i++){
        for(int j=0;j<=w;j++){
            int nottake = dp[i-1][j];
            int take = INT_MIN;
            if(wt[i]<=j) take = val[i] + dp[i-1][j-wt[i]] ;
            dp[i][j] = max(take,nottake);
        }
    }
    
    return dp[n-1][w];
}

//space optimisation
int knapSack(int w, int wt[], int val[], int n) 
{ 
    // Your code here
    vector<int> curr(w+1,0), prev(w+1,0);
    for(int i = wt[0];i<=w;i++) prev[i] = val[0];
    
    for(int i=1;i<n;i++){
        for(int j=0;j<=w;j++){
            int nottake = prev[j];
            int take = INT_MIN;
            if(wt[i]<=j) take = val[i] + prev[j-wt[i]] ;
            curr[j] = max(take,nottake);
        }
        prev = curr;
    }
    
    return prev[w];
}