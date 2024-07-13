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
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1=0,cnt2=0;
        int el1 = INT_MIN,el2=INT_MIN;
        for(int i=0;i<n;i++){
            if(cnt1==0 && nums[i]!=el2){
                el1 = nums[i];
                cnt1 = 1;
            }
            else if(cnt2==0 && el1!=nums[i]){
                el2 = nums[i];
                cnt2 = 1;
            }
            else if(nums[i]==el1) cnt1++;
            else if(nums[i]==el2) cnt2++;
            else cnt1--,cnt2--;
        }
        cnt1=0;
        cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el1) cnt1++;
            if(nums[i]==el2) cnt2++;
        }

        vector<int> ls;
        if(cnt1 > floor(n/3*1.0)) ls.push_back(el1);
        if(cnt2>floor(n/3*1.0)) ls.push_back(el2);
        sort(ls.begin(),ls.end());
        return ls;
    }
};