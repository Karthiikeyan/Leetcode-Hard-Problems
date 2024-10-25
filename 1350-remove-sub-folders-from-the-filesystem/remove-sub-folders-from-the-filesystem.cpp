class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        for(int i=0;i<folder.size();i++){
            folder[i] += "/";
        }
        sort(folder.begin(), folder.end());
        for(auto it: folder) cout<<it<<" ";

        unordered_map<string, int> ump;
        vector<string> ans;
        for(auto it: folder){
            bool flag = true;
            string str = "";
            for(auto i: it){
                str += i;
                if(i=='/' && ump.find(str)!=ump.end()){
                    flag = false;
                    break;
                }
            }
            if(flag){
                ump[str]+=1;
                str.pop_back();
                ans.push_back(str);
            }
        } 
        return ans;
    }
};