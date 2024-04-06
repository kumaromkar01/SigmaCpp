#include<iostream>
using namespace std;
void sort(int arr[],int size){
    for(int i=0;i<size;i++){
        int smaller = i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[smaller]){
                smaller = j;
            }

        }
        swap(arr[smaller],arr[i]);
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