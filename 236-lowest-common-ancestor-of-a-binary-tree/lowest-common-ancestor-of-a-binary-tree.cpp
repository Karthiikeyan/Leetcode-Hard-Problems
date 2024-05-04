/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void parent(unordered_map<TreeNode*, TreeNode*> &par, TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                par[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                par[node->right] = node;
                q.push(node->right);
            } 
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> par;
        unordered_set<TreeNode*> vis;
        parent(par, root);

        queue<TreeNode*> q1;
        q1.push(p);
        while(!q1.empty()){
            TreeNode* node = q1.front();
            q1.pop();
            vis.insert(node);
            if(node==root) break;
            q1.push(par[node]);
        }   

        queue<TreeNode*> q2;
        q2.push(q);
        while(!q2.empty()){
            TreeNode* node = q2.front();
            q2.pop();
            if(vis.count(node)) return node;
            if(node==root) break;
            q2.push(par[node]);
        }
        return NULL;
    }
};