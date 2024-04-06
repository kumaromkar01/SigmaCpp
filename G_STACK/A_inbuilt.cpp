#include<iostream>
#include<stack>
using namespace std;
int  main(){
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);
    cout <<"first element : "<< s.top()<<endl;
    s.pop();
    cout <<"whether it is empty or not : " << s.empty()<<"\n";
    int n = s.size();
    cout<<"size of stack :" << n<<endl;
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}