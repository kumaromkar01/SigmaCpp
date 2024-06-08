

class Solution {
public:
    void solve(int ind,vector<int> &arr, int n,int k,
    vector<vector<int>> &ans,vector<int> temp)
    
    {
        if(k==0){
            if(n==0) ans.push_back(temp);
            return;
        }
        if(ind<0) return;

        //nontake
        solve(ind-1,arr,n,k,ans,temp);
        //take
        if(n>=arr[ind]){
            temp.push_back(arr[ind]);
            solve(ind-1,arr,n-arr[ind],k-1,ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> arr = {1,2,3,4,5,6,7,8,9};
        vector<vector<int>> ans;
        solve(8,arr,n,k,ans,{});
        return ans;
    }
};