// program to check whether all alphabets are there in string or not

#include<iostream>
#include<set>
#include<algorithm>
using namespace std;


bool check(string s);
int main(){
    string s;
    getline(cin,s);
    cout<<check(s);
    return 0;
}
bool check(string s ){
    if(s.length()>26) return false;
    // to convert string to lower case
    transform(s.begin(),s.end(),s.begin(),::tolower);
    set<char> alphabet;
    for(auto ch: s){
        alphabet.insert(ch);
    }
    return (alphabet.size()==26);
}
