// Given a set of N jobs where each jobi has a deadline and profit associated with it.
// Each job takes 1 unit of time to complete and only one job can be scheduled at a time. 
// We earn the profit associated with job if and only if the job is completed by its deadline.
// Find the number of jobs done and the maximum profit.
// Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job. 
// Deadline of the job is the time before which job needs to be completed to earn the profit.


// Example 1:

// Input:
// N = 4
// Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
// Output:
// 2 60
// Explanation:
// Job1 and Job3 can be done with
// maximum profit of 60 (20+40).


static bool cmp(Job a,Job b){
    return a.profit>b.profit;
}
//Function to find the maximum profit and the number of jobs done.
vector<int> JobScheduling(Job arr[], int n) 
{ 
    // your code here
    sort(arr,arr+n,cmp);
    int maxiDeadLine = INT_MIN;
    for(int i=0;i<n;i++){
        maxiDeadLine = max(maxiDeadLine,arr[i].dead);
    }
    vector<int> schedule(maxiDeadLine+1,-1);
    int cnt =0;
    int maxProfit = 0;
    for(int i=0;i<n;i++){
        int currProfit = arr[i].profit;
        int currJob = arr[i].id;
        int currDead = arr[i].dead;
        for(int k = currDead;k>0;k--){ //mind that k>=0 will give wrong answer
            if(schedule[k]==-1){
                cnt++;
                maxProfit+=currProfit;
                schedule[k]=currJob;
                break;
            }
            
        }
    }
    vector<int> ans;
    ans.push_back(cnt);
    ans.push_back(maxProfit);
    return ans;
    
    
} 