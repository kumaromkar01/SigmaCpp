#include<iostream>
#include<string>

using namespace std;

string toBinary(int n ){
      string ans = "";
      while(n>0){
            int rem = n % 2;
            ans = (rem==1?'1':'0') + ans;
            n=n/2;
      }
      cout<<ans<<endl;
}

int toDecimal(string s){
      int num = 0, p2=1, len = s.size();
      for(int i=len-1;i>=0;i--){
            if(s[i]=='1') num = num+p2;
            p2 = 2*p2;
      }
      return num;
}

int main(){
      cout<<toDecimal("101");
}