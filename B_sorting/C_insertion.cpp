#include<iostream>
using namespace std;
void sort(int arr[],int n){
    for (int i = 1; i < n; i++) {
            int curr=arr[i],previous=i-1;
            while (previous>=0&&arr[previous]>curr) {
                arr[previous+1]=arr[previous];
                previous--;
            }
            arr[previous+1]=curr;
        }
}
int main(){
    int arr[]={5,4,3,2,1};
    sort(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}