// Boyer-Moore Voting Algorithm,


//majority element 1 leetcode 169
class Solution {
public:

    
    int majorityElement(vector<int>& nums) {
        int cnt = 0;
        int el  = nums[0];
        for(int i=0;i<nums.size();i++){
            if(cnt ==0){
                el = nums[i];
                cnt = 1;
            }
            else if(nums[i]==el){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        int cnt1 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==el) cnt1++;
        }
        return cnt1>floor(nums.size()/2)?el:-1;
    }
};

//Majority element 2 leetcode 229
