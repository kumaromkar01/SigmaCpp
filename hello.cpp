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
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    int i=0,j=n-1;

    for(int x=0;x<k && i<=j;x++){
        if(x%2==0){
            arr[i]--;
            if(arr[i]==0) i++;
        }
        else{
            arr[j]--;
            if(arr[j]==0) j--;
        }
    }
    cout<<(n-1)-j + i<<endl;

}


int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();        
    }
    return 0;
}