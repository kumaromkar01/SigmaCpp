class Solution {
public:
    void nextPermutation(vector<int>& num) {
        int n= num.size();
        int ind = -1;
        //find rightmost break point
        for(int i=n-2;i>=0;i--){
            if(num[i+1]>num[i]){
                ind = i;
                break;
            }
        }
        //if not found then array is in decreasing order
        // so return the array in sorted order
        if(ind==-1){
            reverse(num.begin(),num.end());
            return ;
        }
        //swap the break point index by just greater element
        for (int i = n - 1; i > ind; i--) {
            if (num[i] > num[ind]) {
                swap(num[i], num[ind]);
                break;
            }
        }
        //reverse the second half
        reverse(num.begin() + ind + 1, num.end());
        return ;
    }
};