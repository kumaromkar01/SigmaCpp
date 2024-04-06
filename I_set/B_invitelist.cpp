#include<iostream>
#include<set>

using namespace std;

int main(int argc, const char** argv) {
    set<string> list;
    int n;
    cin>>n;
    while(n-->=0){
        string name;
        getline(cin,name);
        list.insert(name);
    }
    for(auto i = list.begin();i!=list.end();i++){
        cout<<* i<<endl;
    }

    return 0;
}