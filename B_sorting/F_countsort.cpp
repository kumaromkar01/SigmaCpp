#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

void sort(int arr[], int n)
{
    // Getting the max value from array
    int maxm = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxm = max(maxm, arr[i]);
    }

    // Getting frequency of each element
    int count[maxm + 1] = {0}; // Initialize count array with all zeros

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    // Rearranging array into increasing order
    int j = 0;
    for (int i = 0; i <= maxm; i++) // Change the loop condition
    {
        while (count[i] > 0)
        {
            arr[j] = i;
            count[i]--;
            j++;
        }
    }
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    sort(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
