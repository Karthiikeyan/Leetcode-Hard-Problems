class Solution {
public:
    string simplifyPath(string path) {
        int n = path.size();
        stack<string> st;
        int i=0;
        while(i<n){
            string temp = "";
            while(i<n && path[i]!='/'){
                temp += path[i];
                i++;
            }
            i++;
            if(temp.size()==0 || temp==".") continue;
            else if(temp==".."){
                if(!st.empty()) st.pop();
            }  
            else st.push(temp);
        }
        string ans = "";
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans.size()==0 ? "/" : ans;
    }
};