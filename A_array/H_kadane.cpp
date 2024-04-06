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
