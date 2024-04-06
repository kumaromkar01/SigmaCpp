//memorisation 

class Solution {
public:
    bool solve(int i, string s, unordered_set<string> &dict,int dp[]){
        if(i==s.size()) return true;
        string temp = "";
        if(dp[i]!=-1) return dp[i];
        for(int j = i;j<s.size();j++){
            temp+=s[j];
            if(dict.find(temp)!=dict.end()){
                if(solve(j+1,s,dict,dp)) return true;
            }
        }
        return dp[i]=false;

    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int dp[301]; //as max size is constrainted as 300
        for(int i=0;i<301;i++) dp[i]=-1;
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        return solve(0,s,dict,dp);
    }
};

//bottom up approach
class Solution {
public:
    bool wordBreak(string s, vector<string>& Dict) {
        if(Dict.size()==0) return false;
        unordered_set<string> dict(Dict.begin(),Dict.end());
        vector<bool> dp(s.size()+1,false);
        dp[0]=true;
        
        for(int i=1;i<=s.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(dp[j])
                {
                    string word = s.substr(j,i-j);
                    if(dict.find(word)!= dict.end())
                    {
                        dp[i]=true;
                        break; //next i
                    }
                }
            }
        }
        
        return dp[s.size()];
    }
};