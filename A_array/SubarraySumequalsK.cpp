

//leetcode 560
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int n = nums.size();
        int prefixSum = 0,cnt =0;
        m[0]=1;
        for(int i=0;i<n;i++){
            prefixSum+=nums[i];
            
            int remove = prefixSum-k;

            cnt+=m[remove];
            m[prefixSum]+=1;
        }
        return cnt;
    }
};