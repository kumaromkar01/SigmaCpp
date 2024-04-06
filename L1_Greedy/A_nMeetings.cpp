// Job sequencing problem
//gfg
    static bool comp(pair<int,int> a, pair<int,int> b){
        if(a.second<b.second) return true; //if allready in sorted order then ok
        return false; 
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),comp);
        int cnt = 1;
        int ansEnd = v[0].second;
        for(int i=0;i<n;i++){
            if(v[i].first>ansEnd){
                cnt++;
                ansEnd = v[i].second;
            }
        }
        return cnt;
    }