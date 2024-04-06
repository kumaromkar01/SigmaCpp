https://leetcode.com/problems/dota2-senate/?envType=study-plan-v2&envId=leetcode-75

class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> qr,qd;
        for(int i=0;i<senate.size();i++) 
            if(senate[i]=='R') qr.push(i);
            else qd.push(i);

        while(!qr.empty() && !qd.empty()){
            int a = qr.front(); qr.pop();
            int b = qd.front(); qd.pop();

            if(a<b) qr.push(a+senate.size());
            else qd.push(b+senate.size());
        }

        if(qr.size()==0) return "Dire";
        return "Radiant";
    }
};


//optimised
class Solution {
public:
    string predictPartyVictory(string senate) {
   
        int score = 0; // +ve for R and -ve for D
        for (int i = 0; i < senate.size(); ++i) {
            const char ch = senate[i];
            if (ch == 'R') {
                if (score < 0) senate.push_back('D');
                ++score;
            } 
            else {
                if (score > 0) senate.push_back('R');
                --score;
            }
        }
        return score > 0 ? "Radiant" : "Dire";
 
   }
};