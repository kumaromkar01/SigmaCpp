//A digit string is good if the digits (0-indexed) 
//at even indices are even and the digits at odd indices are prime (2, 3, 5, or 7).
// Given an integer n, return the total number of good digit strings of length n. 
// Since the answer may be large, return it modulo 109 + 7.

// A digit string is a string consisting of digits 0 through 9 that may contain leading zeros.

class Solution {
public:
    long MOD = 1000000007;
    int countGoodNumbers(long long n) {
        long even = (n+1)/2;
        long odd = n/2;

        long first = pow(5,even) %MOD;
        long second = pow(4,odd) %MOD;
        return (int)((first*second)%MOD);
    }
    long pow(long x,long n){
        if(n==0) return 1;
        long temp = pow(x,n/2);
        if(n%2==0) return (temp*temp)% MOD;
        return (x*temp*temp)%MOD;
    }
};