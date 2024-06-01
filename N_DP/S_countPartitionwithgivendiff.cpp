//

// memoization
int mod = 1000000007;
int countPartitionsUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{

    if (ind == 0){
        if (target == 0 && arr[0] == 0) return 2;
        if (target == 0 || target == arr[0])  return 1;
        return 0;
    }
    if (dp[ind][target] != -1) return dp[ind][target];
    int notTaken = countPartitionsUtil(ind - 1, target, arr, dp);
    int taken = 0;
    if (arr[ind] <= target)
    taken = countPartitionsUtil(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = (notTaken + taken) % mod;
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int totSum = 0;
    for (int i = 0; i < arr.size(); i++)totSum += arr[i];
    if (totSum - d < 0) return 0;
    if ((totSum - d) % 2 == 1)return 0;
    int s2 = (totSum - d) / 2;
    vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
    return countPartitionsUtil(n - 1, s2, arr, dp);
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
int countPartitions(int n, int d, vector<int>& arr) {
    // Code here
    int totsum =0;
    for(int i: arr) totsum+=i;
    if(totsum-d<0) return 0;
    if((totsum-d)%2==1) return 0;
    return solve((totsum-d)/2,arr);
}