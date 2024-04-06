#include <iostream>
using namespace std;

void merge(int arr[], int si, int mid, int ei)
{
    int temp[ei - si + 1];
    int i = si;      // for left sorted;
    int j = mid + 1; // for right sorted
    int k = 0;       // for temp

    while (i <= mid && j <= ei)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= ei)
    {
        temp[k++] = arr[j++];
    }
    for (k = 0, i = si; k < ei - si + 1; k++, i++)
    {
        arr[i] = temp[k];
    }
}
void mergesort(int arr[], int si, int ei)
{
    if (si >= ei)
        return;
    int mid = (ei + si) / 2;
    mergesort(arr, si, mid);
    mergesort(arr, mid + 1, ei);
    merge(arr, si, mid, ei);
}
int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    mergesort(arr, 0, 4);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}