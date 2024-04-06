#include<bits/stdc++.h>
using namespace std;
int main() {
    int arr[] = {2, 3, 4, 76, 8, 5, 6};
    int size = 7;
    int biggest = INT_MIN;
    for(int i=0;i<7;i++){
        biggest = max(biggest,arr[i]);
    }
    cout<<biggest;

    return 0;
}
