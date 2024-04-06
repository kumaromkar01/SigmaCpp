// every row and col must have a queen such that no two attack any other leetcode 51
// bruteforce
class Solution {
public:
    bool isSafe(int row,int col, vector<string> &board,int n){
        int duprow = row;
        int dupcol = col;

        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        row = duprow; col = dupcol;
        
        while(row<n && col>=0){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }

        row = duprow;col = dupcol;
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }

        return true;
    }
    void solve(int col,vector<string> &board,vector<vector<string>> &ans,int n){
        if(col==n){
            ans.push_back(board);
            return;
        }
        for(int row =0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,board,ans,n);
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++) board[i]=s;
        solve(0,board,ans,n);
        return ans;
        
    }

};

//optimised
class Solution {
public:
    void solve(int col,vector<string> &board,vector<vector<string>> &ans,
                vector<int> &leftR,vector<int> &upperD,vector<int> &lowerD,int n){
                    if(col == n){
                        ans.push_back(board);
                        return;
                    }
                    for(int row = 0;row<n;row++){
                        if(leftR[row]==0 && lowerD[row+col]==0 && upperD[n-1+col-row]==0){
                            board[row][col]='Q';
                            leftR[row] =1;
                            lowerD[row+col]=1;
                            upperD[n-1+col-row]=1;
                            solve(col+1,board,ans,leftR,upperD,lowerD,n);
                            board[row][col]='.';
                            leftR[row]=0;
                            lowerD[row+col]=0;
                            upperD[n-1+col-row]=0;
                        }
                    }
                }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++) board[i]=s;
        vector<int> leftRow(n,0), upperDiag(2*n-1,0), lowerDiag(2*n-1,0);
        solve(0,board,ans,leftRow,upperDiag,lowerDiag,n);
        return ans;
        
    }

};