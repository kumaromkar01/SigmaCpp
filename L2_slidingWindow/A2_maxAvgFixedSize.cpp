//leetcode easy

// You are given an integer array nums consisting of n elements, and an integer k.
// Find a contiguous subarray whose length is equal to k that has the maximum average value and 
// return this value. Any answer with a calculation error less than 10-5 will be accepted.

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int i=0,j=0, sum =0;
        int maxim = INT_MIN;
        while(j<n){
            sum+=nums[j];
            if(j-i+1==k){
                maxim = max(sum,maxim);
                sum-=nums[i];
                i++;
            }
            j++;
        }
        return double(maxim*1.0/k);
    }
};