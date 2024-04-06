//technique to optimise the code using memorisation
//gfg contest 140, find Fun

//given base case  upto 3
//if n is even s(n)=s(n-2)*(n-2)+s(n-4)*(n-4)
//if n is odd s(n)=s(n-1)*(n-1) + s(n-3)*(n-3)
    long long solve(int n, vector<long long>& memo) {
        int MOD = 1000000007;
        if (n == 0) return 2;
        if (n == 1) return 5;
        if (n == 2) return 9;
        if (n == 3) return 7;
        if (n == 4) return 18;
        if (n == 5 || n == 6) return 90;
        if (memo[n] != -1) {
            return memo[n];
        }
        if (n % 2 == 0) {
            memo[n] = solve(n - 1, memo);
        } else {
            memo[n] = solve(n - 1, memo) * (n - 1) + solve(n - 3, memo) * (n - 3);
        }
        return memo[n] % MOD;
    }
    int findFun(int n) {
        int MOD = 1000000007;
        vector<long long> memo(n + 1, -1);
        long long ans = solve(n, memo);
        return static_cast<int>(ans % MOD);
    }