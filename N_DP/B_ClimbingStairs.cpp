//recursion time limit exceded at 31/45 for n = 45
class Solution {
public:
    int ways(int i){
        if(i==0) return 1;
        if(i==1) return 1;
        return ways(i-1)+ways(i-2);
    }
    int climbStairs(int n) {
        return ways(n);
    }
};

//memorisation
class Solution {
public:
    int ways(int i,vector<int>&dp){
        if(i==0) return 1;
        if(i==1) return 1;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=ways(i-1,dp)+ways(i-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return ways(n,dp);
    }
};

//tabulation
class Solution {
public:
    
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

// space optimisation
class Solution {
public:
    
    int climbStairs(int n) {
        int prev2=1;
        int prev1=1;
        for(int i=2;i<=n;i++){
            int curr=prev1+prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};