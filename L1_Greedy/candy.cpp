// //leetcode hard
// There are n children standing in a line. 
// Each child is assigned a rating value given in the integer array ratings.
// You are giving candies to these children subjected to the following requirements:
// Each child must have at least one candy.
// Children with a higher rating get more candies than their neighbors.
// Return the minimum number of candies you need to have to distribute the candies to the children.
// Example 1:
// Input: ratings = [1,0,2]
// Output: 5
// Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
//bruteForce
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> c(n,1);
        if(ratings.size()>=2) if(ratings[0]>ratings[1]) c[0]=c[1]+1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]) {
                c[i]=c[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                c[i]=max(c[i],c[i+1]+1);
            }
        }
        return accumulate(c.begin(),c.end(),0);
    }
};
