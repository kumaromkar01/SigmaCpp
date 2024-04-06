//leetcode

class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, string& s){
        if(!s.size()) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]!=s[0]) return false;
        char c = board[i][j];
        board[i][j]='*';
        string str=s.substr(1);
        bool ret = dfs(board,i+1,j,str) || dfs(board,i-1,j,str) || dfs(board,i,j+1,str) || dfs(board,i,j-1,str);
        board[i][j]= c;
        return ret;

    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(board,i,j,word))  return true;
            }
        }
        return false;
    }
};