class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        map<double, string> mp;
        int n = arr.size();
        priority_queue<pair<double,vector<int>>> pq;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                pq.push({-((double)arr[i]/arr[j]), {arr[i], arr[j]}});
            }
        }
        
        k -= 1;
        while(k--){
            pq.pop();
        }
        return pq.top().second;
    }
};