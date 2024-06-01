//perfect sum gfg
//https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=perfect-sum-problem

//memoization
int solve(int ind, int arr[],  int target,vector<vector<int>> &dp)
	{   
	    if(ind==0) {
	        if(target==0 && arr[0]==0) return 2;
	        if(arr[0]==target || target==0) return 1;
	        return 0 ;
	    }
	    if(dp[ind][target]!=-1) return dp[ind][target];
	    int nottake = solve(ind-1,arr,target,dp);
	    int take = 0;
	    if(arr[ind]<=target) take = solve(ind-1,arr,target-arr[ind],dp);
	    return dp[ind][target] = (take + nottake) % 1000000007;
	}
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return solve(n-1,arr,sum,dp);
	}

//tabulation
int solve(int target, vector<int> &arr){
    int n= arr.size();
    vector<vector<int>> dp(n,vector<int>(target+1,0));
    if(arr[0]==0) dp[0][0] = 2;
    else dp[0][0] = 1;
    if(arr[0]<=target && arr[0]!=0)dp[0][arr[0]] = 1;
    for(int i=1;i<n;i++){
        for(int tar = 0;tar<=target;tar++){
            int nottake = dp[i-1][tar];
            int take = 0;
            if(arr[i]<=tar) take = dp[i-1][tar-arr[i]];
            dp[i][tar] = (take+nottake)%1000000007;
        }
    }
    return dp[n-1][target];
}