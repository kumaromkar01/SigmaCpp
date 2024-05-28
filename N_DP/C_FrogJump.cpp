//https://www.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump
//recursion
int solve(int ind, vector<int> &height){
    //this function tells the min enery for reaching ind index of array
    if(ind==0) return 0;
    int left = solve(ind-1,height)+abs(height[ind]-height[ind-1]);
    int right = INT_MAX;
    if(ind>1) right = solve(ind-2,height)+abs(height[ind]-height[ind-2]);
    
    return min(left,right);
}
int minimumEnergy(vector<int>& height, int n) {
    // Code here
    return solve(n-1,height);
}

//memoizzation
int solve(int ind, vector<int> &height,vector<int> &dp){
    //this function tells the min enery for reaching ind index of array
    if(ind==0) return dp[0]=0;
    if(dp[ind]!=-1) return dp[ind];
    int left = solve(ind-1,height,dp)+abs(height[ind]-height[ind-1]);
    int right = INT_MAX;
    if(ind>1) right = solve(ind-2,height,dp)+abs(height[ind]-height[ind-2]);
    
    return dp[ind]=min(left,right);
}
int minimumEnergy(vector<int>& height, int n) {
    // Code here
    vector<int> dp(n,-1);
    return solve(n-1,height,dp);
}

//tabulation
int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n);
        dp[0]=0;
        if(n>1) dp[1]=1;
        
        for(int i=1;i<n;i++){
            int left = dp[i-1]+abs(height[i-1]-height[i]);
            int right = INT_MAX;
            if(i>1) right = dp[i-2]+abs(height[i-2]-height[i]);
            dp[i]=min(left,right);
        }
        return dp[n-1];
    }
// space optimised
int minimumEnergy(vector<int>& height, int n) {
        // Code here
        int prev=0,prev1;
        if(n>1) prev1=1;
        
        for(int i=1;i<n;i++){
            int left = prev+abs(height[i-1]-height[i]);
            int right = INT_MAX;
            if(i>1) right = prev1+abs(height[i-2]-height[i]);
            int curr =min(left,right);
            prev1 = prev;
            prev  = curr;
        }
        return prev;
    }