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
    TreeNode* invertTree(TreeNode* root) {
        if (root==nullptr) return root;
        if(root->left==nullptr and root->right==nullptr){
            TreeNode *node;
            return node;
        }
        std::swap(root->left,root->right);
        TreeNode* rl=invertTree(root->left);
        TreeNode* rr=invertTree(root->right);
        root->left=rl;
        root->right=rr;
        return root;
    }
};