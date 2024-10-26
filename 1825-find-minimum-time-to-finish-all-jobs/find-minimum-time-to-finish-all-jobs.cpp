class Solution {
private:
    bool valid(int ind, int limit, int k, vector<int>workers, vector<int>&jobs){
        if(ind==jobs.size()) return true;
        for(int i=0;i<k;i++){
            if(workers[i] + jobs[ind] <= limit){
                workers[i] += jobs[ind];
                if(valid(ind+1, limit, k, workers, jobs)) return true;
                workers[i] -= jobs[ind];
            }
            if(workers[i]==0) return false;
        }
        return false;
    }
public:
    int minimumTimeRequired(vector<int>& jobs, int k){
        int low = 0, high = 0, n = jobs.size(), ans = 0;
        for(int i=0;i<n;i++){
            low = max(low, jobs[i]);
            high +=  jobs[i];
        }

        while(low <= high){
            int mid = low + (high - low) / 2;
            vector<int> workers(k, 0);
            if(valid(0, mid, k, workers, jobs)){
                ans = mid;
                high = mid - 1;
            }else
                low = mid + 1;
        }
        return ans;
    }
};