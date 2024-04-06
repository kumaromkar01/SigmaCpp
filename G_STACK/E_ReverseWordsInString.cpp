class Solution {
public:
    string reverseWords(string s) {
        string temp ="";
        stack<string> st;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(ch==' '){
                if(temp!="") st.push(temp);
                temp="";
            }
            else{
                temp+=ch;
            }
        }
        if(temp!=""){
            st.push(temp);
            temp="";
        }

        while(!st.empty()){
            temp+=(st.top()+" ");
            st.pop();
        }
        temp.pop_back();
        return temp;
    }
};