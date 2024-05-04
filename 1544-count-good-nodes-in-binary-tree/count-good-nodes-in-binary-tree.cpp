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
    void preorder(TreeNode* root, int maxi, int &ans){
        if(root==NULL) return;
        if(root->val>=maxi){
            ans++;
            maxi = root->val;
        }
        preorder(root->left, maxi, ans);
        preorder(root->right, maxi, ans);
    }
public:
    int goodNodes(TreeNode* root) {
        int ans = 0;
        preorder(root, root->val, ans);
        return ans;
    }
};