#include<bits/stdc++.h>
using namespace std;
void search(int arr[],int key,int size){
    int si=0,ei=size-1;
    while(si<ei){
        int mid = (si+ei)/2;
        if(arr[mid]==key){
            cout<<"found at "<<mid<<endl;
            break;
        }
        else if (arr[mid]<key)
        {
            si = mid+1;
        }
        else{
            ei = mid-1;
        }
    }
}
int main(){
    int arr[]={1,2,3,4,5,6,7};
    int key = 4;
    int size = 7;
    search(arr,key,size);
    return 1;
}