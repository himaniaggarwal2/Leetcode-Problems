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
    void traverse(vector<int> &result, TreeNode* root){
        if(root==nullptr) return ;
        if(root->left==nullptr and root->right==nullptr){
            result.push_back(root->val);
            return;
        }
        
        if(root->left!=nullptr) traverse(result,root->left);
        result.push_back(root->val);
        if(root->right!=nullptr) traverse(result,root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result={};
        traverse(result,root);
        return result;
    }
};