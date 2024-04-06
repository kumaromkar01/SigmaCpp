//string to integer leetcode

class Solution {
public:
    int myAtoi(string s) {
        int i =0,sign =1,total =0,n=s.size();
        while(i<n && s[i]==' ') i++;
        // + or - ek hi bar aan chahiye
        // +-12  --> 0
        if(i<n &&(s[i]=='+'||s[i]=='-'))
        sign = s[i++]=='+'?1:-1;
        while(i<n){
            int digit = s[i]-'0';
            if(digit<0 || digit>9) break;
            if(total >INT_MAX/10 || total == INT_MAX /10  && INT_MAX %10 <digit ){
                return sign==-1?INT_MIN:INT_MAX;
            }
            total = 10 *total +digit;
            i++;
        }
        return total*sign;
    }
};