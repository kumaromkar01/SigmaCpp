//leetcode 75


//Given an integer array nums, return true if there exists a triple of indices (i, j, k) 
//such that i < j < k and nums[i] < nums[j] < nums[k]. If no such indices exists, return false.


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int c1 =INT_MAX,c2=INT_MAX;
        for(auto i: nums){
            if(i<=c1){
                c1=i;
            }
            else if(i<=c2){
                c2=i;
            }
            else return true;
        }
        return false;
    }
};