class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        stack<int> st;
        int n = asteroids.size();

        for(int i=0; i<n; i++){
            int x = asteroids[i];
            bool flag = 1;
            while(!st.empty() && st.top() > 0 && x < 0){
                int first = st.top();
                int second = abs(x);
                st.pop();

                if(first > second){
                    x = first;
                }   

                else if(first == second){
                    flag = 0;
                    break;
                }
            }
            if(flag) st.push(x);
        }
        
        n = st.size();
        vector<int> ans(n);
        n--;
        while(!st.empty()){
            ans[n] = st.top();
            st.pop();
            n--;
        }
        return ans;
    }
};