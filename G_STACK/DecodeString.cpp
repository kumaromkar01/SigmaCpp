//https://leetcode.com/problems/decode-string/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    string decodeString(string s) {
        string ans ="";
        stack<char> st;
        for(char c : s){
            if(c==']'){
                while(!st.empty() && st.top()!='['){
                    ans=st.top()+ans;
                    st.pop();
                }
                // pop out '[' from stack
                if(!st.empty()) st.pop();
                //extracting digit
                string number = "";
                while(!st.empty() && st.top()>='0' &&  st.top()<='9'){
                    number=st.top()+number;
                    st.pop();
                }

                int digit = stoi(number);
                string temp = "";
                for(int i=0;i<digit;i++){
                    temp+=ans;
                }
                for(char c : temp){
                    st.push(c);
                }
                ans="";

            }
            else st.push(c);
        }
        while(!st.empty()){
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};