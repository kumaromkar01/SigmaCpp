

vector<long long int> dp;
    long long int bottomUpHelper(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (dp[n] != -1) return dp[n];
        dp[n] = (bottomUpHelper(n - 1) + bottomUpHelper(n - 2)) % 1000000007;
        return dp[n];
    }
    
    long long int bottomUp(int n) {
        dp.assign(n + 1, -1);
        return bottomUpHelper(n);
    }
    long long int topDown(int n) {
        // code here
        long long i = 0;
        long long j = 1;
        int curr;
        if(n==0 || n==1) return n;
        for(int x=2;x<=n;x++){
            curr = (i+j)%1000000007;
            i=j;
            j=curr;
        }
        return j;
        
    }