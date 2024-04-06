//leetcode
// Given a binary array nums and an integer k, return the maximum number of consecutive 1's 
// in the array if you can flip at most k 0's.
// Example 1:
// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i =0,cnt = 0;
        int maxi = INT_MIN;
        for(int j =0;j<nums.size();j++){
            if(nums[j]==0) {
                cnt++;
            }
            while(cnt>k){
                if(nums[i]==0) {
                    cnt--;
                }
                i++;
            }
            maxi  = max(maxi,j-i+1);
        }

        return maxi;
    }
};