//leetcode 131

class Solution {
public:
    bool isPalin(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    void solve(string s,vector<vector<string>> &ans, vector<string> &path, int index){
        if(index==s.size()){
            ans.push_back(path);
            return ;
        }
        for(int i=index;i<s.size();i++){
            if(isPalin(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                solve(s,ans,path,i+1);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(s,ans,path,0);
        return ans;
    }
};