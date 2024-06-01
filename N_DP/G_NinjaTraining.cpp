// gfg
//https://www.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training

// recursion
int solve(int day, int last, vector<vector<int>> &points)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
                maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }

    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        int point;
        if (i != last)
            point = points[day][i] + solve(day - 1, i, points);
        maxi = max(point, maxi);
    }
    return maxi;
}
int maximumPoints(vector<vector<int>> &points, int n)
{
    // Code here
    return solve(n - 1, 3, points);
}

//memoization
int solve(int day,int last,vector<vector<int>> &points,vector<vector<int>> &dp){
      if(dp[day][last]!=-1) return dp[day][last];
      if(day==0){
          int maxi = 0;
          for(int i=0;i<3;i++){
              if(i!=last) maxi = max(maxi,points[0][i]);
          }
          return dp[day][last]=maxi;
      }
      int maxi = 0;
      for(int i=0;i<3;i++){
          int point=0 ;
          if(i!=last) point=points[day][i]+solve(day-1,i,points,dp);
          maxi = max(point,maxi);
      }
      return dp[day][last]=maxi;
      
  }
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> dp(n,vector<int> (4,-1));
        return solve(n-1,3,points,dp);
    }

//tabulation
int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> dp(n,vector<int> (4,0));
        for(int i=0;i<3;i++){
            dp[0][i]=max(points[0][(i+1)%3],points[0][(i+2)%3]);
        }
        
        for(int day = 1;day<n;day++){
            for(int last = 0;last<4;last++){
                dp[day][last]=0;
                int maxi = 0;
                for(int task = 0;task<3;task++){
                    if(task!=last){
                        int point = points[day][task]+dp[day-1][task];
                        maxi = max(maxi,point);
                    }
                }
                dp[day][last]=maxi;
            }
        }
        return dp[n-1][3];
    }