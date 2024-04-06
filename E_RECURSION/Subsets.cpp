// print all subsequences of an array

class Solution {
public:
    void solve(vector<vector<int>> &subsets,vector<int> v, int i,vector<int> &nums){
        if(i>=nums.size()) {
            subsets.push_back(v);
            return;
        }
        //take
        v.push_back(nums[i]);
        solve(subsets,v,i+1,nums);
        v.pop_back();
        //not take
        solve(subsets,v,i+1,nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> v;
        solve(subsets,v,0,nums);
        return subsets;
    }
};


// optimised

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        int n = nums.size();
        
        for (int i = 0; i < (1 << n); i++) {
            vector<int> subset;
            for (int j = 0; j < n; j++) {
                if (i & (1 << j)) {
                    subset.push_back(nums[j]);
                }
            }
            subsets.push_back(subset);
        }
        
        return subsets;
    }
};
