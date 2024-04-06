//given two vectors find sum of common elements in them
#include<iostream>
#include<set>
#include<vector>

using namespace std;
 
int main(int argc, const char** argv) {
    vector<int> v1 = {1,1,2,3,3,3};
    vector<int> v2 ={5,6,7,5,3,2,6};
    int sum =0;
    set<int> s;
    for(int ele: v1){
        s.insert(ele);
    }
    for(int elem: v2){
        if(s.find(elem)!=s.end()){
            sum+=elem;
        }
    }
    cout<<sum<<endl;
    return 0;
}