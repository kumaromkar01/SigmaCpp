
//leetcode HouseRobber2 213
class Solution {
public:
    //optimised code of houseRobber 1
    long long maximumNonAdj(vector<int> &nums){
        int n = nums.size();
        long long prev = nums[0];
        long long prev2 = 0;
        for(int i=1;i<n;i++){
            long long take = nums[i];
            if(i>1) take+=prev2;
            long long notTake = prev;
            long long curri = max(take,notTake);
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        //since house are cicular so we will have different array having or not haveing 0/n-1 to calculate max.
        vector<int> temp1,temp2;
        int n = nums.size();
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        return max(maximumNonAdj(temp1),maximumNonAdj(temp2));
    }
};