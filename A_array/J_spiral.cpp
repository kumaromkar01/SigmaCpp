#include<iostream>
#include<Array>
using namespace std;
void spiral(int arr[4][4],int size){
    int startrow =0,startcol = 0,endrow = size-1,endcol = size-1;
    while(startrow<=endrow&&startcol<=endcol){
        for(int j=startcol+1;j<=endcol;j++){
            cout<<arr[startrow][j]<<" ";
        }
        for(int i=startrow+1;i<=endrow;i++){
            cout<<arr[i][endcol]<<" ";

        }
        for(int j=endcol-1;j>=startcol;j--){
            cout<<arr[endrow][j]<<" ";
        }
        for(int i=endrow-1;i>=startrow+1;i--){
            cout<<arr[i][startcol]<<" ";
        }
        startrow++;
        endrow--;
        startcol++;
        endcol--;
    }
}
int main(){
    int arr[4][4]={{1,2,3,4},
                     {5,6,7,8},
                     {9,10,11,12},
                     {13,14,15,16}};
    spiral(arr,4);
}