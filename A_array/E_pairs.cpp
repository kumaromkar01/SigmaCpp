#include<iostream>
using namespace std;
int pairs(int arr[],int n){
    //total pairs = n*(n-1)/2
    int total=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cout<<'('<<arr[i]<<" "<<arr[j]<<')';
            total++;
        }
        cout<<endl;
    }
    cout<<"total pairs : "<<total;
}
int main(){
    int arr[]={1,2,3,4,5,6,7,9,8};
    pairs(arr,9);
    return 0;
}