
//recursion
class Solution {
public:
    int solve(int ind, vector<int> &nums, int target){
        if(ind==0){
            if(abs(target)==abs(nums[0]) && nums[0]==0) return 2;
            else if(abs(target)==abs(nums[0]) ) return 1;
            else return 0;
        }
        int plus = nums[ind]+solve(ind-1,nums,target-nums[ind]);
        int minus = -nums[ind]+solve(ind-1,nums,target+nums[ind]);
        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(n-1,nums,target);
    }
};

//tabulation striver's approach
// actually you have to divide the array into two subsets such that the difference of their sum is equal to target.
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
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return countPartitions(n,target,nums);
    }