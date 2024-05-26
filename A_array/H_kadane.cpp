#include<iostream>
#include<climits>
using namespace std;

int maxsum(int num[], int n) {
    int sum = 0;
    int maxmsum = INT_MIN;

    for (int i = 0; i < n; i++) {
        sum += num[i];
        maxmsum = max(maxmsum, sum);
        if (sum < 0) {
            sum = 0;
        }
    }

    cout << maxmsum;
}

int main() {
    int num[] = { -1, -2, -3 };
    maxsum(num, 3);
    return 0;
}
//leetcode 53
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxi = INT_MIN;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<0) sum= 0;
            maxi =max(maxi,sum);
        }
        return maxi;
    }
};