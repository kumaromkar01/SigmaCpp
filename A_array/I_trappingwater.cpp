#include<iostream>
using namespace std;
int trap(int arr[],int size){
    int left[size]={0}; 
    int right [size]={0};
    left[0] = arr[0]; 
    right[size-1] = arr[size-1];
    for(int i=0;i<size;i++){
        left[i] = max(left[i-1],arr[i]);
        right[i]=max(right[i-1],arr[i]);
    }
    int trapped =0;
    for(int i=0;i<size;i++){
        int sum = min(left[i],right[i])-arr[i];
        if(sum<0) sum =0;
        trapped+=sum;
    }
    return trapped;
}
int main(){
    int arr[]={4,2,0,6,3,2,5};
    int size = 7;
    cout<<trap(arr,size);
}