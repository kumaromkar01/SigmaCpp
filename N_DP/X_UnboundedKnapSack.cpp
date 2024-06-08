// gfg  
//https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

//memoization
int helper(int ind, int w, int val[], int wt[],vector<vector<int>> &dp){
    if(ind==0){
        return w/wt[0] * val[0];
    }
    if(dp[ind][w]!=-1) return dp[ind][w];
    int notTake = helper(ind-1,w,val,wt,dp);
    int take = INT_MIN;
    if(w>=wt[ind]) take = val[ind]+helper(ind,w-wt[ind],val,wt,dp);
    return dp[ind][w]=max(take,notTake);
}
int knapSack(int N, int W, int val[], int wt[])
{
    // code here
    vector<vector<int>> dp(N,vector<int> (W+1,-1));
    return helper(N-1,W,val,wt,dp);
    
}

//tabulation
int knapSack(int N, int W, int val[], int wt[])
{
    // code here
    vector<vector<int>> dp(N,vector<int> (W+1,0));
    for(int w=0;w<=W;w++){
        dp[0][w] = w / wt[0] * val[0];
    }
    
    for(int ind =1;ind<N;ind++){
        for(int w=0;w<=W;w++){
            int notTake = dp[ind-1][w];
            int take = INT_MIN;
            if(w>=wt[ind]) take = val[ind]+dp[ind][w-wt[ind]];
            dp[ind][w]=max(take,notTake);
        }
    }
    return dp[N-1][W];
}       