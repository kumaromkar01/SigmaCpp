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

//leetcode 54
//perfect code :
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        vector<int> ans;
        int rows = m.size();
        if (rows == 0) return ans; // Handling edge case of empty matrix
        int cols = m[0].size();
        int startRow = 0, endRow = rows - 1;
        int startCol = 0, endCol = cols - 1;
        while (startRow <= endRow && startCol <= endCol) {
            // Traverse right
            for (int j = startCol; j <= endCol; j++) {
                ans.push_back(m[startRow][j]);
            }
            startRow++;

            // Traverse down
            for (int i = startRow; i <= endRow; i++) {
                ans.push_back(m[i][endCol]);
            }
            endCol--;

            // Traverse left (if needed)
            if (startRow <= endRow) {
                for (int j = endCol; j >= startCol; j--) {
                    ans.push_back(m[endRow][j]);
                }
                endRow--;
            }

            // Traverse up (if needed)
            if (startCol <= endCol) {
                for (int i = endRow; i >= startRow; i--) {
                    ans.push_back(m[i][startCol]);
                }
                startCol++;
            }
        }
        return ans;
    }
};