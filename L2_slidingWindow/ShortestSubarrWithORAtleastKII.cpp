// https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/description/


class Solution {
public:
    void performOpr(int &num,int &orVal, vector<int>&bitCount){
        orVal = orVal | num;
        //update bitCount
        for(int i=0;i<32;i++){
            //if ith bit is set
            if(num & (1<<i)) bitCount[i]+=1;
        }
    }
    void revertOp(int &num,int& orVal, vector<int> &bitCount){
        //update bit count
        for(int i=0;i<32;i++){
            // if ith bit is set
            if(num & (1<<i)) bitCount[i] -= 1;
            //bitcount[i] becomes 0 --> unset ith bit
            if(bitCount[i]==0) orVal = orVal & (~(1<<i));
        }
    }
    int minimumSubarrayLength(vector<int>& nums, int k) {
        //expand right boundary and whenever you get a solution 
        // shrink the left boundary
        int ans = INT_MAX;
        int orVal = 0;
        vector<int> bitCount(32,0);
        int l = 0;
        int r  = 0;
        for(;r<nums.size();r++){
            //expand right boundary include rth element
            performOpr(nums[r],orVal,bitCount);

            while(l<=r && orVal >= k){
                ans = min(ans,r-l+1);
                revertOp(nums[l],orVal,bitCount);
                l++;
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};