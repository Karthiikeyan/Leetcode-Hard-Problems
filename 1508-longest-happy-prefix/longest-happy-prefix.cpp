class Solution {
public:
    string longestPrefix(string s) {
	    int n = s.size();
	    vector<int> v(n, 0);
	    
	    int pref = 0, suff = 1;
	    while(suff < n){
	        if(s[pref] == s[suff]){
	            v[suff] = pref + 1;
	            pref++, suff++;
	        }else{
	            if(pref==0){
	                v[suff] = 0;
	                suff++;
	            }else{
	                pref = v[pref-1];
	            }
	        }
	    }
	    return v.back()!=0 ? s.substr(0, v.back()) : "";
    }
};