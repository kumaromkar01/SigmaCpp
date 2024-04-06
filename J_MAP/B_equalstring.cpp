//array of string is given , we can move any number of charachters of one string to other 
//check whether all the strings can be made equal or not
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
bool check(vector<string> v){
    unordered_map <char, int> m;
    for(string str: v){
        for(char c: str){
            m[c]++;
        }
    }
    int n = v.size();
    for(auto ele: m){
        if(ele.second%n!=0){
            return false;
        }
    }
    return true;
}
int main(int argc, const char** argv) {
    vector<string> s ={"collegeee","coll","collegge"};
    cout<<check(s)<<endl;
    return 0;
}