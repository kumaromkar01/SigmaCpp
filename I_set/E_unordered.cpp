#include<iostream>
#include<unordered_set>

using namespace std;

int main(){
    unordered_set<int> s;
    
    s.insert(1); //t.c for sungle element O(1) or O(N i.e size of set) per element
    // O(n) or O(n*(N+1) ) for multiple elements
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(6);
    s.insert(5);
    
    cout<<"unordered set is : \n";
    for(int val: s) cout<<val<<" ";
    cout<<endl;

    //memeber functions
    //1>
    s.erase(3);
    for(int val: s) cout<<val<<" ";
    cout<<endl;
    s.erase(s.begin());
    for(int val: s) cout<<val<<" ";
    cout<<endl;
    //s.erase(strating index , ending index)


    //2>
    // s.find() return s.end( ) if not found else returns an iterator for that
    //s.count()  returns number of occurences i.e. 0 or 1
    // load_factor() 
    //rehash()
    // size , max_size , begin, end will work in same way
    //s.clear()  to clear all set


    return 0;

}