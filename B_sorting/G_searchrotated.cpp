#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int searchSorted(vector<int> nums,int target, int si, int ei){
        //base case
        if(si>ei){
            return -1;
        }
        int mid = (si+ei)/2;
        //case found
        if(nums[mid]==target){
            return mid;
        }
        //mid on line 1
        if(nums[si]<=nums[mid]){
            //case a :
            if(nums[si]<=target && target <=nums[mid]){
                return searchSorted ( nums,target,si,mid-1);
            }
            else{
                return searchSorted(nums,target, mid+1,ei);
            }
        }
        //mid on line 2
        else{
            if(nums[mid]<=target&&target<=nums[ei]){
                return searchSorted(nums, target, mid+1, ei);
            }
            else{
                return searchSorted(nums, target, si, mid-1);
            }
        }

    }
    int search(vector<int>& nums, int target) {
        int start =0, end = nums.size()-1;
       
        return searchSorted(nums,target,start,end);
    }
    
};