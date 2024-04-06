//leetcode 75

// Given an input string s, reverse the order of the words.
// A word is defined as a sequence of non-space characters. 
// The words in s will be separated by at least one space.
// Return a string of the words in reverse order concatenated by a single space.
// Note that s may contain leading or trailing spaces or multiple spaces between two words. 
// The returned string should only have a single space separating the words. Do not include any extra spaces.

//corner cases : " world hello " o/p: "hello world"
class Solution {
public:
    string reverseWords(string s) {
        string ans ="";
        string temp="";
        reverse(s.begin(),s.end());
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                if(temp!=""){
                    reverse(temp.begin(),temp.end());
                ans+=temp;
                ans.push_back(' ');
                temp = "";
                }
            }
            else temp.push_back(s[i]);
        }
        reverse(temp.begin(),temp.end());
        ans+=temp;
        if(ans.back()==' ') ans.pop_back();
        return ans;
    }
};