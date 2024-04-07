class Solution {
public:
    string getSmallestString(string s, int k) {
        for (int i = 0; i < s.size(); ++i) {
            int dist = min(s[i] - 'a', 'z' - s[i] + 1);
            if(k >= dist){
                k -= dist;
                s[i] = 'a';
            }else{
                if(k > 0){
                    if(s[i] - k >= 'a'){
                        s[i]-=k;
                    }else{
                        s[i] = 'z' - (k - 1);
                    }
                    k=0;
                }
                break;
            }
        }
        return s;
    }
};