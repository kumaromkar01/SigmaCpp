class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        long long ans = 0;
        int lastmini = -1, lastmaxi = -1, lastinvalid = -1;

        for(int i=0;i<n;i++){
            //valid range
            if(nums[i]>=minK && nums[i]<=maxK){
                if(nums[i]==minK) lastmini = i;
                if(nums[i]==maxK) lastmaxi = i;
                ans+= max(0,min(lastmini,lastmaxi)-lastinvalid);
            }
            //out of range
            else{
                lastinvalid = i;
                lastmini = -1;
                lastmaxi = -1;
            }
        }
        return ans;
    }
};