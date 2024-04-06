

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt =0,prod =1,i=0,j=0;
        for(;j<nums.size();j++){
            prod*=nums[j];
            while(prod>=k && i<j){
                prod/=nums[i];
                i++;
            }
            if(prod<k) cnt+=j-i+1;
        }
        return cnt;
    }
};