// leetcode 416

//memoization
class Solution {
public:
    bool solve(int target, vector<int> &nums, int ind, vector<vector<int>> &dp){
        if(target ==0 ) return  true;
        if(ind==0) return  nums[0]==target;
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool take = false;
        if(nums[ind]<=target) take = solve(target-nums[ind],nums,ind-1,dp);
        bool nonTake = solve(target,nums,ind-1,dp);
        return dp[ind][target] = take||nonTake;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i: nums) sum+=i;
        if(sum%2!=0) return false;
        int target = sum / 2;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solve(target,nums,n-1,dp);
    }
};

//tabulation
class Solution {
public:
    bool solve(int target, vector<int> &nums){
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int> (target+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=1; // if target is 0 at any indices it is true;
        }

        //below given conditional check is essential in case of [100]
        if(nums[0]<=target) dp[0][nums[0]] = 1; // if you are at 1st element and target equals it then it is true

        for(int i=1;i<n;i++){
            for(int j = 1;j<=target;j++){
                int notTake = dp[i-1][j];
                int take = false;
                if(j>=nums[i]) take = dp[i-1][j-nums[i]];

                dp[i][j] = take | notTake;
            }
        }
        return dp[n-1][target];

    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i: nums) sum+=i;
        if(sum%2!=0) return false;
        int target = sum / 2;
        return solve(target,nums);
    }
};

//space optimised
