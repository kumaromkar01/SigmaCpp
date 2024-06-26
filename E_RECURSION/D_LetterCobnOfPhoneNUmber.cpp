//Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

//A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



class Solution {
public:
    void solve(string digits,string output,int idx,vector<string> &ans,string mapping[]){
        //base case
        if(idx>=digits.length()){
            ans.push_back(output);
            return;
        }
        int number = digits[idx]-'0';
        string value = mapping[number];
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(digits,output,idx+1,ans,mapping);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0) return ans;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(digits,"",0,ans,mapping);
        return ans;
    }
};