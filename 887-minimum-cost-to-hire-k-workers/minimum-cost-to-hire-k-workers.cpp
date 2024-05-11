class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        vector<pair<double, int>> workers;
        for(int i=0;i<n;i++){
            workers.push_back({(wage[i]*1.0)/quality[i], quality[i]});
        }
        sort(workers.begin(), workers.end());
        
        priority_queue<int> pq;
        double ans = DBL_MAX, qltySum = 0;
        for(int i=0;i<n;i++){
            double ratio = workers[i].first;
            qltySum += workers[i].second;
            pq.push(workers[i].second);
            if(pq.size()>k){ 
                qltySum -= pq.top();
                pq.pop();
            }
            if(pq.size()==k) 
                ans = min(ans, ratio * qltySum);
        }

        return ans;
    }
};