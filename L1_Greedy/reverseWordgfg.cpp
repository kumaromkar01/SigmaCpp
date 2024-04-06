// gfg  

// Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

// Example 1:

// Input:
// S = i.like.this.program.very.much
// Output: much.very.program.this.like.i
// Explanation: After reversing the whole
// string(not individual words), the input
// string becomes
// much.very.program.this.like.i


#include<bits/stdc++.h>
using namespace std;
string reverseWords(string s) 
{ 
    // code here 
    string ans="";
    string temp ="";
    for(int i=s.size()-1;i>=0;i--){
        
        
        if(s[i]=='.' ){
            if(temp!=""){
                reverse(temp.begin(),temp.end());
                ans+=temp;
                ans.push_back('.');
                temp ="";
            }
            
            
        }
        else temp.push_back(s[i]);
    }
    if(temp!="") {
        reverse(temp.begin(),temp.end());
        ans+=temp;
    }
    return ans;
} 