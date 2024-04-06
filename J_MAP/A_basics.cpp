#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    map<string,int> dir;
    //for descending order
    //map<string,int, greater<string>> dir;
    map<int,int> x = {{1,2},{2,3},{3,4}};
    for(auto pair: x){
        cout<< pair.first<<" "<<pair.second<<endl;
    }
//insertion  O(logn) or O(n)
    dir.insert(make_pair("ABC",9000));
    dir.insert(make_pair("DEF",8000));
    dir["ghi"] = 7000;
//updation      
    dir["ghi"] = 6000;
    //can't be changed using make_pair
    for(auto pair: dir){
        cout<< pair.first<<" "<<pair.second<<endl;
    }
//deletion
    map<int,int> :: iterator itr;
    itr = x.begin();
    x.erase(itr);
    x.erase(3);
    // multiple deletion
    // map<int,int> :: iterator i = itr;
    // advance(i,2); // will delete 0th and 1st index;
    for(auto pair: x){
        cout<< pair.first<<" "<<pair.second<<endl;
    }

//swaping
    map<int,int> y = {{1,2},{2,3},{3,4}};
    x.swap(y); // swap(x,y);
    cout<<"x is :\n"; 
    for(auto pair: x){
        cout<< pair.first<<" "<<pair.second<<endl;
    }
    cout<<"y is :\n"; 
    for(auto pair: y){
        cout<< pair.first<<" "<<pair.second<<endl;
    }

//clear
    y.clear();
//check empty
    cout<<"is x empty ? :"<<y.empty()<<endl;
//size
    cout<<"size of y and x is : "<<y.size()<<" "<<x.size();
    cout<<"capacity of y and x is : "<<y.max_size()<<" "<<x.max_size()<<endl;

//find  and count
    if(x.find(2)!=x.end()){
        cout<<x.count(2)<<endl;
    }
//bounds
    cout<<"lower_bound: "<<x.lower_bound(2)->first<<" "<<x.lower_bound(2)->second<<endl;
    cout<<"upper_bound: "<<x.upper_bound(2)->first<<" "<<x.upper_bound(2)->second<<endl;
// printing using iterator
    map<int,int> :: iterator it;
    for(it = x.begin();it!=x.end();it++){
        cout<<it->first<<"  "<<it->second<<endl;
    }

//unordered map
    unordered_map<int,int> n;
    n[5]=6;
    n[6]=7;
    n[7]=8;
    for(auto pair: n){
        cout<<pair.first<<" "<<pair.second;
    }
    //memeber function remaining same
    // insertion , deletion , search in O(1) or O(n) : 

//multimap 
    //duplicacy is allowed
    multimap<string,int> directory;
    directory.insert(make_pair("omkar",7479));
    // directory["omkar"] = 619515;  gives compilation error
    directory.insert(make_pair("omkar",619515));
    for(auto pair: directory){
        cout<<pair.first<<" "<<pair.second<<endl;
    }
    cout<<endl<<endl;
    //member function remaining same

//unordered multimap
    unordered_multimap<string,int> fruitcount;
    fruitcount.insert(make_pair("apple",7479));
    fruitcount.insert(make_pair("orange",6195));
    fruitcount.insert(make_pair("apple",15));
    for(auto pair: fruitcount){
        cout<<pair.first<<" "<<pair.second<<endl;
    }
    cout<<endl<<endl;
    return 0;
}
