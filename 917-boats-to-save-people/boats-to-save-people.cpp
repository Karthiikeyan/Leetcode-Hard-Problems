class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int ans = 0;
        sort(people.begin(), people.end());

        int i = 0, j = n-1;
        while(i<=j){
            if((people[i]+people[j]) <= limit) i++;
            ans += 1; j--;
        }
        return ans;
    }
};