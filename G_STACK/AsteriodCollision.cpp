

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for(int a : asteroids){
            bool des = false; // to check whether destroyed or not
            // we have problem only if positive tries to be on left 
            // and negative tries to be on right;
            while(ans.size() && ans.back()>0 && a<0 && !des){
                if(ans.back() >= -a) des = true;
                if(ans.back() <= -a) ans.pop_back();
            }
            //if asteroid is not destroyed then push it to result
            if(!des) ans.push_back(a);
        }
        return ans;
    }
};