//gfg
// Given N activities with their start and finish day given in array start[ ] and end[ ]. 
// Select the maximum number of activities that can be performed by a single person, 
// assuming that a person can only work on a single activity at a given day.
// Note : Duration of the activity includes both starting and ending day.

// Input:
// N = 4
// start[] = {1, 3, 2, 5}
// end[] = {2, 4, 3, 6}
// Output: 
// 3
// Explanation:
// A person can perform activities 1, 2
// and 4.



static bool comp(pair<int,int> a,pair<int,int> b){
        return b.second>a.second;
    }
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int,int>> v;
        for(int i =0;i<n;i++){
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),comp);
        // for(int i=0;i<v.size();i++){
        //     cout<< v[i].first<<" "<<v[i].second<<endl;
        // }
        int endt = v[0].second;
        int cnt =1;
        for(int i=1;i<v.size();i++){
            if(v[i].first>endt){
                cnt++;
                endt=v[i].second;
            } 
        }
        return cnt;
    }