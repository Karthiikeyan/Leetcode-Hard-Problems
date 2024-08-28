class Solution {
private:
    int find(int x, int y, char sign){
        if(sign == '+') return x + y;
        if(sign == '-') return x - y;
        if(sign == '*') return x * y;
        return 0;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;
        bool isTrue = true;

        for(int i=0;i<expression.size();i++){
            if(!isdigit(expression[i])){
                isTrue = false;
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));
                for(auto x : left){
                    for(auto y: right){
                        int num = find(x, y, expression[i]);
                        ans.push_back(num);
                    }
                }
            }
        }

        if(isTrue) ans.push_back(stoi(expression));
        return ans;
    }
};
