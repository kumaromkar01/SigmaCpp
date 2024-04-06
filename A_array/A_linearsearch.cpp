#include<bits/stdc++.h>
using namespace std;

void search(int arr[], int key, int size) {
    for(int i = 0; i < size; i++) {
        if(key == arr[i]) {
            cout << "found at " << i << endl;
            return; // Return after finding the key to stop searching.
        }
    }
    // If key is not found, you can print a message.
    cout << "Key not found." << endl;
}

int main() {
    int arr[] = {2, 3, 4, 76, 8, 5, 6};
    int key = 76;
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    search(arr, key, size);
    return 0;
}
