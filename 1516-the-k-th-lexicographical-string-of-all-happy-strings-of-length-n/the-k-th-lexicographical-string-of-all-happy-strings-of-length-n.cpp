class Solution {
private:
    bool func(string &ans, char last, int &k, int n) {
        if (ans.size() == n) { 
            if (--k == 0) return true;  
            return false;
        }
        
        // Recursive case
        if (last != 'a') {
            ans.push_back('a');
            if (func(ans, 'a', k, n)) return true;
            ans.pop_back();
        }
        if (last != 'b') {
            ans.push_back('b');
            if (func(ans, 'b', k, n)) return true;
            ans.pop_back();
        }
        if (last != 'c') {
            ans.push_back('c');
            if (func(ans, 'c', k, n)) return true;
            ans.pop_back();
        }
        
        return false;
    }

public:
    string getHappyString(int n, int k) {
        int val = 1 << (n - 1);  
        if (3 * val < k) return ""; 
        
        string ans;
        func(ans, '\0', k, n);
        return ans;
    }
};
