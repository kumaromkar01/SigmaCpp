//leetcode
// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
// Example 1:

// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]


class Solution {
public:
    void solve(vector<string> &v, int m,int n,string ans){
        if(n==0 && m==0) {
            v.push_back(ans);
            return;
        }
        if(m>0) solve(v,m-1,n,ans+")");
        if(n>0) solve(v,m+1,n-1,ans+"(");

    }
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        solve(v,0,n,"");
        return v;
    }
};