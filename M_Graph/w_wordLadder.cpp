// part1 leetcode 127

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        set<string> st(wordList.begin(),wordList.end());

        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty()){
            string sabd = q.front().first;
            int steps = q.front().second;
            q.pop();

            if(sabd==endWord) return steps;
            for(int i=0;i<sabd.size();i++){
                char asli = sabd[i];
                for(char c ='a';c<='z';c++){
                    sabd[i]=c;
                    if(st.find(sabd)!=st.end()){
                        q.push({sabd,steps+1});
                        st.erase(sabd);
                    }
                }
                sabd[i]=asli;
            }
        }
        return 0;
    }
};

//part2 leetcode 126