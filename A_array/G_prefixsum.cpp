#include<iostream>
#include<climits>
using namespace std;

int sum(int arr[], int n) {
    int maxm = INT_MIN;
    int prefix[n];
    prefix[0] = arr[0];

    for (int i = 1; i < n; i++) {
        prefix[i] = arr[i] + prefix[i - 1];
    }

    for (int i = 0; i < n; i++) {
        int start = i;
        for (int j = i; j < n; j++) {
            int end = j;
            int add = (i == 0) ? prefix[end] : prefix[end] - prefix[start - 1];
            maxm = max(maxm, add);
        }
    }

    cout << maxm;
    return maxm;
}

int main() {
    int arr[] = {1, -2, 6, -1, 3};
    sum(arr, 5);
    return 0;
}
