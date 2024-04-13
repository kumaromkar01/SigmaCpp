//leetcode 128

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i: nums) s.insert(i);
        int ans = 0;  //in case of [] returns 0
        for(int i:s){
            if(s.find(i-1)==s.end()){
                int cnt = 1;
                int x = i;
                while(s.find(x+1)!=s.end()){
                    cnt++;
                    x=x+1;
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};