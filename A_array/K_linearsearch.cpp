#include<iostream>
using namespace std;
    void print(int matrix[3][3]){
        cout<<"the maatrix is : ";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout<<(matrix[i][j])<<" ";
            }
            cout<<endl;
        }
    }
    void search(int matrix[3][3]){
        int key;
        cin>>key;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if(matrix[i][j]==key){
                    cout<<"found at : ("<<i <<","<<j<<")";
                }
            }
        }
    }
    int main() {
        int matrix[3][3];
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j <3; j++) {
                cin>>matrix[i][j];
            }
        }
        print(matrix);
        search(matrix);
}
