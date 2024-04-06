#include<iostream>
#include<set>
using namespace std;


void print(set<int> s1){
    //declaring iterator 
    set<int> :: iterator itr;
    for(itr = s1.begin();itr!=s1.end();itr++){
        cout<<*itr<<" ";
    }
     cout<<endl;
}


int main(){
    set<int> s;
    //element identified by itself
    //no duplicacy
    //already sorted
    //insertion,deletion,search is in log(N) 
    set<int> s1={1,4,3,2,5};
    s.insert(1);
    s.insert(3);
    s.insert(4);
    print(s1);
   
    s1.erase(3); // remove all occurence of 3 in set


    set<int> :: iterator itr = s1. begin();
    advance(itr,3);  //to move iterator to 4th index
    s1.erase(itr);    // to erase 4th index
    //s1.erase(start pos , end pos itr)  here end pos is not removed

    //member functions
    cout<<"size : "<<s1.size()<<endl;
    cout<<"is set empty : "<<s.empty()<<endl;
    s.clear(); //to clear the set
    cout<<"lower bound : "<<*s1.lower_bound(2)<<endl;
    cout<<"upper bound : "<<*s1.upper_bound(2)<<endl;
    //s.find()  will give index of number else give s.end()
    //s.count()  will give number of occurences i.e. 1 or 0

    // print(s1);
    // 2nd method to print the set
    for(auto val: s1){
        cout<<val<<" ";

    }
    cout<<endl;

    return 0;
}