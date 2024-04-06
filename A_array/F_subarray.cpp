#include<iostream>
#include<climits>
using namespace std;

void subarray(int arr[], int n) {
    int maxsum = INT_MIN;
    for (int i = 0; i < n; i++) {
        int start = i;
        for (int j = i; j < n; j++) {
            int end = j, sum = 0;
            for (int k = start; k <= end; k++) { // Corrected the loop condition
                cout << arr[k] << " ";
                sum += arr[k];
            }
            cout << endl;
            maxsum = max(sum, maxsum);
        }
    }
    cout << maxsum;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5, 6 };
    subarray(arr, 6);
    return 0;
}

