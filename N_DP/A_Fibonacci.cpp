// #include<bits/stdc++.h>
#include<vector>
#include<iostream>
using namespace std;
//recursion
int fib(int n){
    if(n<=1) return n;
    return fib(n-1)+fib(n-2);
}

//memorisation
int n;
vector<int> dp(n+1,-1); //to get upto nth term taking 0th term idexing.
int fib(int  i, vector<int> &dp){
    if(i<=1) return n;
    if(dp[i]!=-1) return dp[i];

    return dp[i]= fib(n-1)+fib(n-2);
}

//tabulation
vector<int> Series(int n) {
    // Code here
    vector<int> ans(n+1);
    int mod = 1000000007;
    ans[0]=0;
    ans[1]=1;
    for(int i=2;i<=n;i++){
        ans[i]=(ans[i-1]+ans[i-2])%mod;
    }
    return ans;
}

// with optimised space for nth term
int fib(int n){
    int prev2 = 0;
    int prev = 1;
    for(int i=0;i<n;i++){
        int curri = prev2+prev;
        prev2=prev;
        prev = curri;
    }
    return prev;
}