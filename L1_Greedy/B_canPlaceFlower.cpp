//leetcode 75

// bruteforce approach

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flower, int n) {

        vector<int> temp(flower.begin(),flower.end());
        int init =0;
        for(int i=0;i<temp.size();i++) if(temp[i]==1) init++;
        if(temp.size()==1){
            if(temp[0]==0) return n<=1;
        }
        if(temp.size()>1) if(temp[1]!=1) temp[0]=1;
        for(int i=1;i<temp.size()-1;i++){
            if(temp[i-1]!=1 && temp[i+1]!=1) temp[i]=1;
        }
        if(temp.size()>=2) if(temp[temp.size()-2]!=1) temp[temp.size()-1]=1;
        int cnt=0;
        for(int i=0;i<temp.size();i++){
            // cout<<temp[i]<<" ";
            if(temp[i]==1) cnt++;
        }

        if(cnt-init>=n) return true;
        return false;
    }
};

//optimised

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flower, int n) {
        vector<int> temp(flower.begin(),flower.end());
        int cnt =0;
        for(int i=0;i<temp.size();i++){
            if(flower[i]==0){
                int prev = (i==0)?0:temp[i-1];
                int next = (i==temp.size()-1)?0:temp[i+1];
                if(prev!=1 && next!=1){
                    cnt++;
                    temp[i]=1;
                }
            }
        }
        return cnt>=n;
    }
};