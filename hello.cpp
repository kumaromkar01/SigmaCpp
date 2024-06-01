#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// #define get(a) cin>>a
// #define put(a) cout<<a
// #define getarr(n,arr) for(int i=0;i<n;i++) cin>>arr[i];
#define f first
#define s second
#define pb push_back
#define endl '\n'

const int mod = 1e9 + 7;
template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T>>;


void solve(){
    

}


int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        // solve(); 
        int matrix[5][5];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>matrix[i][j];
        }
    }    

    int row,col;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(matrix[i][j]==1) {
                row = i;
                col = j;
            }
        }
    }

    int ans = row+col-4;
    cout<<ans<<endl;       
    }
    return 0;
}