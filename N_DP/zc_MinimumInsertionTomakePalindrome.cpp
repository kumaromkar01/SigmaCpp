//leetcode

//not working solution triggered in brain
//fails in test case 18/58 zjveiiwvc
class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                ans++;
                i++;
            }
        }
        return ans;
    }
};


//actually you have to return n-LCS

class Solution {
public:
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        int n= s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        int lcs = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    lcs = max(lcs,dp[i][j]);
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return n-lcs;
    }
};