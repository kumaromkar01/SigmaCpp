#include<iostream>
#include<forward_list>
using namespace std;

int main(){
    forward_list<int> l; // declaring a linked list.
    l.assign({1,2,3,4,5,6});
    //printing list
    for(int &a : l){
        cout<<a<<" ";
    }cout <<endl;

    forward_list<int> l1 ={1,2,3,4,4,5};
    for(int &a : l1){
        cout<<a<<" ";
    }cout <<endl;
    // re-assigning the list
    l1.assign(5,10);
    for(int &a : l1){
        cout<<a<<" ";
    }cout <<endl;


    // copying contents of one list to other
    l1. assign(l.begin(),l.end());
    for(int &a : l1){
        cout<<a<<" ";
    }cout <<endl;

    // push-front or emplace_front;
    // no coping is done in emplace_front
    l1.push_front(2);
    for(int &a : l1){
        cout<<a<<" ";
    }cout <<endl;

    //l1. pop_front
    l1.pop_front();
    for(int &a : l1){
        cout<<a<<" ";
    }cout <<endl;

    l1.insert_after(l1.begin(), { 1, 1, 30 }); 
    for(int &a : l1){
        cout<<a<<" ";
    }cout <<endl;
    // remove all instances of 1
    l1.remove(1);
    for(int &a : l1){
        cout<<a<<" ";
    }cout <<endl;

    //remove all instances of elements greater than 2
    l1.remove_if([](int x) { return x > 2; });
    for(int &a : l1){
        cout<<a<<" ";
    }cout <<endl;

    //clear entire list
    l1.clear();
    l.clear();

    //sorting the list
    forward_list<int> l2{1,5,3,2,4};
    l2.sort();
    for(int &a : l2){
        cout<<a<<" ";
    }cout <<endl;

    //reverse the list
    l2.reverse();
    for(int &a : l2){
        cout<<a<<" ";
    }cout <<endl;

    //swap two lists

    forward_list<int> l3{1,2,3,4,5};
    swap(l2,l3);
    cout<<"list 2"<<endl;
    for(int &a : l2){
        cout<<a<<" ";
    }cout <<endl;

    cout<<"list 3"<<endl;
    

	forward_list<int>::iterator it;
	for (it = l3.begin(); it != l3.end(); ++it)
		cout <<" "<< *it;
	cout << '\n';

    return 0;
}