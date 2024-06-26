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
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> nodes;
        inorder(root, nodes);
        return buildBST(nodes, 0, nodes.size() - 1);
    }
private:
    void inorder(TreeNode* node, vector<TreeNode*>& nodes) {
        if (node == NULL) return;

        inorder(node->left, nodes);
        nodes.push_back(node);
        inorder(node->right, nodes);
    }
    TreeNode* buildBST(vector<TreeNode*>& nodes, int left, int right) {
        if (left > right) return NULL;

        int mid = left + ((right - left) >> 1);
        TreeNode* node = nodes[mid];
        node->left = buildBST(nodes, left, mid - 1);
        node->right = buildBST(nodes, mid + 1, right);
        return node;
    }
};