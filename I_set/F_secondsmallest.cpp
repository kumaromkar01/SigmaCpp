//given n integers find the 2nd smallest
#include<iostream>
#include<set>
// note: memeber functions are same and work similarly on unordered and ordered multiset also
// erase, find, count, lower_bound, uppere_bound, 
// also duplicacy is allowed in multisets.
// time complexity is same as ordered and unordered
using namespace std;

int main(){
    int n;
    cin>>n;
    multiset<int> s;
    for(int i=0;i<n;i++){
        int x;
        cin>> x;
        s.insert(x);

    }
    multiset <int> :: iterator itr =s.begin();
    itr++;
    cout<<*itr;
    return 0;
}