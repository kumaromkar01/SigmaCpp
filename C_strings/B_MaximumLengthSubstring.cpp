//leetcode
//Given a string s, return the maximum length of a substring 
//such that it contains at most two occurrences of each character.
 

int maximumLengthSubstring(string s){
        int maxl = 0;
        map<char,int> m;
        int left=0,right=0;
        for (right = 0; right < s.size(); right++){
            if (m.find(s[right]) != m.end()){
                m[s[right]]++;
                while (m[s[right]] > 2){
                    m[s[left]]--;
                    if (m[s[left]] == 0){
                        m.erase(s[left]);
                    }
                    left++;
                }
            } 
            else m[s[right]]++;
            maxl = max(maxl, right - left + 1);
        }
        return maxl;
    }