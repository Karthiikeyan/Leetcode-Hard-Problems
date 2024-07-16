class Solution {
public:
    struct Query{
        int ind, visit;
        Query(int _ind, int _vis){
            ind = _ind;
            visit = _vis;
        }

        bool operator < (const Query& rhs) const {
            return visit < rhs.visit;
        }
    };
    vector<int> fullBloomFlowers(vector<vector<int>>& f, vector<int>& people) {
        map<int,int> mpp;
        for(auto it: f){
            mpp[it[0]]++;
            mpp[it[1]+1]--;
        }

        vector<Query> queries;
        for(int i=0;i<people.size();i++){
            queries.push_back(Query(i, people[i]));
        }

        sort(queries.begin(), queries.end());

        int qI = 0;
        int prefSum = 0;
        int q = queries.size();
        vector<int> ans(q);

        for(auto it: mpp){
            int currTime = it.first;
            while(qI < q && queries[qI].visit < currTime){
                ans[queries[qI].ind] = prefSum;
                qI += 1;
            }
            prefSum += it.second;
        }
        return ans;
    }
};