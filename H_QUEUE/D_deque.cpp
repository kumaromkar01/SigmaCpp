#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(15);
    dq.push_back(30);
    //other functions are also there like  pop_back(), clear(), push_back(), push_front(), pop_front() and so on
    

    // m1 to print;
    // while(!dq.empty()){
    //     cout<<dq.front()<<" ";
    //     dq.pop_front();
    // }
    //dq.clear();


    //m2 to print
    for(auto i = dq.begin();i<dq.end();i++){
        cout<<" "<<*i;
    }
    return 0;
}