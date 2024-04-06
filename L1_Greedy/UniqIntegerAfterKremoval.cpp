// Given an array of integers arr and an integer k. 
// Find the least number of unique integers after removing exactly k elements.
// Input: arr = [4,3,1,1,3,3,2], k = 3
// Output: 2
// Explanation: Remove 4, 2 and either one of the two 1s or three 3s. 1 and 3 will be left.


//bruteForce

class Solution {
public:
    static bool cmp(pair<int,int> a,pair<int,int> b){
        return b.second>a.second;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        vector<pair<int,int>>  v(m.begin(),m.end());
        sort(v.begin(),v.end(),cmp);
        int x =0;
        while(k>=0 && x<v.size()){
            k-=v[x].second;
            if(k>=0)  x++;
        }
        return v.size()-x;

    }
};

//optimised

class Solution {
public:
    
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        sort(arr.begin(),arr.end());
        vector<int> v;  //to store freq
        int cnt = 1; //already counted freq of 1st element
        for(int i=1;i<arr.size();i++){
            if(arr[i]==arr[i-1]){
                cnt++;
            }
            else{
                v.push_back(cnt);
                cnt = 1;
            }
        }
        v.push_back(cnt); //freq of last element
        sort(v.begin(),v.end());
        int x =0;
        while(k>=0 && x<v.size()){
            k-=v[x];
            if(k>=0)  x++;
        }
        return v.size()-x;

    }
};