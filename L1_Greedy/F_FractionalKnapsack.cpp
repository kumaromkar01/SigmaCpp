//gfg
// Given weights and values of N items, we need to put these items in a knapsack of capacity W to get 
// the maximum total value in the knapsack.
// Note: Unlike 0/1 knapsack, you are allowed to break the item here. 

// Example 1:

// Input:
// N = 3, W = 50
// value[] = {60,100,120}
// weight[] = {10,20,30}
// Output:
// 240.000000
// Explanation:
// Take the item with value 60 and weight 10, value 100 and weight 20 and split the third item with value 
// 120 and weight 30, to fit it into weight 20. so it becomes (120/30)*20=80, so the total value 
// becomes 60+100+80.0=240.0
// Thus, total maximum value of item we can have is 240.00 from the given capacity of sack. 

 static bool cmp(pair<double,Item>a,pair<double,Item>b){
        return a.first>b.first;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int k, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,Item>> v;
        for(int i=0;i<n;i++){
            double perUnit =(1.0*arr[i].value)/arr[i].weight;
            pair<double,Item> p = {perUnit,arr[i]};
            v.push_back(p);
        }
        sort(v.begin(),v.end(),cmp);
        double profit=0;
        for(int i=0;i<n;i++){
            if(v[i].second.weight>k){
                profit+=k*v[i].first;
                k =0;
            }
            else{
                profit+=v[i].second.value;
                k-=v[i].second.weight;
            }
        }
        return profit;
    }