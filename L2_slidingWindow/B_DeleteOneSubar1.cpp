//lletcode

//maximum length of subarray after deleting one element
#include<bits/stdc++.h>
using namespace std;

//bruteforce
class Solution {
public:
    int n;
    int findMax(vector<int> &nums,int &skip){
        int maxi = 0;
        int cur = 0;
        for(int i=0;i<n;++i){
            if(i==skip) continue; //index to skip
            else if(nums[i]==1){ 
                cur++; //size of subarray
                maxi = max(maxi,cur);

            }
            else{
                cur =0; //if 0 is found even after getting ignoring skip then new subarray to search
            }
        }
        return maxi;
    }
    int longestSubarray(vector<int>& nums) {
        int result = 0;
        n = nums.size();
        int countZ=0;
        for(int i=0;i<n;++i){  //traverse entire array 
            if(nums[i]==0){  //if 0 is found ignore that index and get size of maximum sub array
                countZ++;
                result = max(result,findMax(nums,i));
            }
        }
        if(countZ==0) return n-1;  //[1,1,1] return 2 as we have to delete any one
         return result;
    }
};

//optimise using sliding window
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxLen = 0;
        int countZ =0;
        int i=0;
        for(int j =0;j<nums.size();j++){
            if(nums[j]==0) countZ++;
            while(countZ>1){
                if(nums[i]==0) countZ--;
                i++;
            }
            maxLen = max(maxLen,j-i);  //since we have to delete 1 elements anyhow, so window size is decreased by 1as j-i
        }
        return maxLen;
    }
};

//better sliding window
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxLen = 0;
        int last_zero_idx = -1;
        int i=0;
        for(int j =0;j<nums.size();j++){
            if(nums[j]==0){
                i = last_zero_idx+1;
                last_zero_idx = j;
            }
            maxLen = max(maxLen,j-i);  //since we have to delete 1 elements anyhow, so window size is decreased by 1as j-i
        }
        return maxLen;
    }
};

