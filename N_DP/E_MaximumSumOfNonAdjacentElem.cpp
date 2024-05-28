//leetcode house Robber 198

//memoization
class Solution {
public:
    int solve(int ind, vector<int> &nums,vector<int> &dp){
        //this function provides the best value by lootiong from  0 to ind(included)
        if(ind==0) return dp[0]=nums[0];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        //pick current house i.e not looted last house
        int pick = solve(ind-2,nums,dp)+nums[ind];
        int nonPick = solve(ind-1,nums,dp)+0;

        return dp[ind]=max(pick,nonPick);

    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(n-1,nums,dp);
    }
};

//tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int nonpick = dp[i-1];
            int pick;
            if(i<2) pick=nums[i];
            else pick = nums[i]+dp[i-2];
            dp[i]= max(pick,nonpick);
        }
        return dp[n-1];
    }
};
// space optimise
//dp[i-2] = prev, i-1=prev1, i = curr