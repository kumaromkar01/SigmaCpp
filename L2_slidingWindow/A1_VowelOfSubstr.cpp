//leetcode
// Given a string s and an integer k, return the maximum number of vowel letters 
// in any substring of s with length k.
// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
// Example 1:

// Input: s = "abciiidef", k = 3
// Output: 3
// Explanation: The substring "iii" contains 3 vowel letters.
//basic approach using slidinng window
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxVowels(string s, int k) {
        int i = 0, j = 0;
        int maxim = 0;
        int curr = 0;
        while (j < s.size()) {
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u') curr++;
            if(j-i+1==k){
                maxim = max(maxim,curr);
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') curr--;
                i++;
                j++;
            }
            else if(j-i+1<k){
                j++;
            }
        }
        return maxim;
    }
};

//slightly optimised sw
int maxVowels(string s, int k) {
        int i = 0, j = 0;
        int maxim = 0;
        int curr = 0;
        while (j < s.size()) {
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') {
                curr++;
            }
            if (j - i + 1 == k) {
                maxim = max(maxim, curr);
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                    curr--;
                }
                i++;
            }
            j++;
        }
        return maxim;
    }
};
