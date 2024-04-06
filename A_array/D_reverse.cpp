#include<iostream>
using namespace std;
void reverse(int arr[],int n){
    int si=0,ei=n-1;
    while(si<ei){
        //swap
        swap(arr[si],arr[ei]);
        si++;
        ei--;
    }

}
int main(){
    int arr[]={5,3,7,2,8,1,9};
    reverse(arr,7);
    for(int i=0;i<7;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}