//https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/description/?envType=daily-question&envId=2024-03-29

class Solution {
public:
    long long countSubarrays(std::vector<int>& nums, int k) {
        long long n = nums.size(); 
        long long maxi = *std::max_element(nums.begin(), nums.end()); 
        long long i = 0, j = 0, cnt = 0, ans = 0;
        for (j = 0; j < n; j++) {
            if (nums[j] == maxi) {
                cnt++; 
            }
            while(cnt >= k){
                // total possible subarrays having the [i,j] are i+1+n-1-j
                // but since we had already taken subarrays before ith indx in
                // consideration. so we will worry about right part of subarray 
                //only. 
                ans += n - j;
                if (nums[i] == maxi) {
                    cnt--; 
                }
                i++;
            }
        }
        return ans;
    }
};

