/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    vector<vector<int>> ans;
private:
    void dfs(TreeNode* node, int target, vector<int>&temp, int sum){
        if(node->left==NULL && node->right==NULL){
            sum += node->val;
            temp.push_back(node->val);
            if(sum==target){
                ans.push_back(temp);
            }
            sum -= node->val;
            temp.pop_back();
        }
        
        temp.push_back(node->val);
        sum += node->val;
        if(node->left) dfs(node->left, target, temp, sum);
        if(node->right) dfs(node->right, target, temp, sum);
        sum -= target;
        temp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        if(root==NULL) return ans;
        dfs(root, targetSum, temp, 0);
        return ans;
    }
};