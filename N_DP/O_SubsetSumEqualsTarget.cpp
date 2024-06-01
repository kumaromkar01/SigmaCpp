//subset sum problem gfg

//recursion
bool solve(int ind,int target,vector<int> &arr){
    if(target == 0 ) return true;
    if(ind==0) return arr[0]==target;
    bool notTake = solve(ind-1,target, arr);
    bool take = false;
    if(arr[ind]<=target) take = solve(ind-1,target-arr[ind],arr);
    return take||notTake;
}
bool isSubsetSum(vector<int>arr, int sum){
    // code here 
    int n = arr.size();
    return solve(n-1,sum,arr);
}

//memoization
bool solve(int ind,int target,vector<int> &arr,vector<vector<int>> &dp){
    if(target == 0 ) return true;
    if(ind==0) return arr[0]==target;
    if(dp[ind][target]!=-1) return dp[ind][target];
    bool notTake = solve(ind-1 ,target ,arr ,dp);
    bool take = false;
    if(arr[ind]<=target) take = solve(ind-1,target-arr[ind],arr,dp);
    return dp[ind][target] = take||notTake;
}
bool isSubsetSum(vector<int>arr, int sum){
    // code here 
    int n = arr.size();
    vector<vector<int>> dp(n,vector<int>(sum+1,-1));
    return solve(n-1,sum,arr,dp);
}

//tabulation
bool isSubsetSum(vector<int>arr, int sum){
    // code here 
    int n = arr.size();
    vector<vector<bool>> dp(n,vector<bool>(sum+1,0));
    for(int i=0;i<n;i++) dp[i][0]=true;
    dp[0][arr[0]] = true;
    for(int ind = 1 ; ind<n; ind++){
        for(int target = 1; target <=sum; target++){
            bool notTake = dp[ind-1][target];
            bool take = false;
            if(arr[ind]<=target) take = dp[ind-1][target - arr[ind]];
            dp[ind][target] = take | notTake;
        }
    }
    return dp[n-1][sum];
}