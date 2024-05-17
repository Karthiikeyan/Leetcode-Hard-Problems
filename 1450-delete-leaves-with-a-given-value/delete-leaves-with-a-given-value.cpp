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
private:
    void solve(TreeNode* &root, int target){
        if(!root) return;
        solve(root->left, target);
        solve(root->right, target);
        if(root->left==NULL && root->right==NULL && target==root->val) root = NULL;
        return;
    }
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        solve(root, target);
        return root;
    }
};