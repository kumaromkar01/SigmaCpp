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
    int n; cin>>n;
    string s = to_string(n);
    int ans = 0;
    for(int i=0;i<s.size();i++){
        if(i==0 && s[0]=='9') ans+=9;
        else ans=10*ans+min(s[i]-'0','9'-s[i]);
    }
    cout<<ans<<endl;
}


int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();        
    }
    return 0;
}