#include<iostream>
using namespace std;
void bubble(int arr[],int size){
    
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
    
}


int main(){
    int arr[]={5,4,3,2,1};
    bubble(arr,5);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}