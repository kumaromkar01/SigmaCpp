#include<iostream>
using namespace std;

int partition(int arr[], int si, int ei) {
    // int pivot = arr[ei];
    int i =si-1;
    for (int j = si; j < ei; j++) {
        if (arr[j] < arr[ei]) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[ei]);
    return i;
}
void quickSort(int arr[], int si, int ei) {
    if (si < ei) {
        int pidx = partition(arr, si, ei);
        quickSort(arr, si, pidx - 1);
        quickSort(arr, pidx + 1, ei);
    }
}
int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
