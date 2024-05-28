//    https://www.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost 

//recursion
int solve(int ind,vector<int> &height, int &k){
    if(ind==0) return 0;
    int miniCost = INT_MAX;
    for(int i=1;i<=k;i++){
        int cost = INT_MAX;
        if(ind-i>=0)
        cost = solve(ind-i,height,k)+abs(height[ind]-height[ind-i]);
        miniCost = min(miniCost,cost);
    }
    return miniCost;
}
int minimizeCost(vector<int>& height, int n, int k) {
    // Code here
    
    return solve(n-1, height,k);
}

//memoizaton

int solve(int ind,vector<int> &height, int &k,vector<int> &dp){
    if(ind==0) return dp[0]=0;
    if(dp[ind]!=-1) return dp[ind];
    int miniCost = INT_MAX;
    for(int i=1;i<=k;i++){
        int cost = INT_MAX;
        if(ind-i>=0)
        cost = solve(ind-i,height,k,dp)+abs(height[ind]-height[ind-i]);
        miniCost = min(miniCost,cost);
    }
    return dp[ind]=miniCost;
}
int minimizeCost(vector<int>& height, int n, int k) {
    // Code here
    vector<int> dp(n,-1);
    return solve(n-1, height,k,dp);
}

//tabulation

int minimizeCost(vector<int>& height, int n, int k) {
    // Code here
    vector<int> dp(n,0);
    dp[0]=0;
    
    for(int i=1;i<n;i++){
        int miniCost = INT_MAX;
        for(int x=1;x<=k;x++){
            int cost = INT_MAX;
            if(i-x>=0) cost = dp[i-x]+abs(height[i]-height[i-x]);
            miniCost = min(cost,miniCost);
        }
        dp[i]=miniCost;
    }
    return dp[n-1];
}
