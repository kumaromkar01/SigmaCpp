//bruteforce

#include <bits/stdc++.h>
using namespace std;

long double minimiseMaxDistance(vector<int> &arr, int k) {
    int n = arr.size(); //size of array.
    vector<int> howMany(n - 1, 0);

    //Pick and place k gas stations:
    for (int gasStations = 1; gasStations <= k; gasStations++) {
        //Find the maximum section
        //and insert the gas station:
        long double maxSection = -1;
        int maxInd = -1;
        for (int i = 0; i < n - 1; i++) {
            long double diff = arr[i + 1] - arr[i];
            long double sectionLength =
                diff / (long double)(howMany[i] + 1);
            if (sectionLength > maxSection) {
                maxSection = sectionLength;
                maxInd = i;
            }
        }
        //insert the current gas station:
        howMany[maxInd]++;
    }

    //Find the maximum distance i.e. the answer:
    long double maxAns = -1;
    for (int i = 0; i < n - 1; i++) {
        long double diff = arr[i + 1] - arr[i];
        long double sectionLength =
            diff / (long double)(howMany[i] + 1);
        maxAns = max(maxAns, sectionLength);
    }
    return maxAns;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}

//better
double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        vector<int> howMany(n-1,0);
        priority_queue<pair<double,int>> pq;
        for(int i=0;i<n-1;i++){
            pq.push({stations[i+1]-stations[i],i});
        }
        for(int s = 1;s<=k;s++){
            int ind = pq.top().second;
            pq.pop();
            
            howMany[ind]++;
            
            double iniDist = stations[ind+1]-stations[ind];
            double segment = iniDist / double(howMany[ind]+1);
            
            pq.push({segment,ind});
        }
        
        return pq.top().first;
}

//optimal
 int inBwn(double dist, vector<int> &stations){
        int cnt = 0;
        for(int i=0;i<stations.size()-1;i++){
            double Inbetween = (stations[i+1]-stations[i])/dist;
            // if(dist * Inbetween == (stations[i+1]-stations[i])){
            //     Inbetween --;
            // }
            cnt+=(int)Inbetween;
        }
        return cnt;
    }
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        double low = 0;
        double high =0;
        
        for(int i=0;i<stations.size()-1;i++){
            double diff = stations[i+1]-stations[i];
            if(high < diff) high = diff;
        }
        
        while(high-low >= 0.0000001){
            double mid = (high+low)/2;
            int cnt = inBwn(mid,stations);
            if(cnt>k){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        return high;
    }
