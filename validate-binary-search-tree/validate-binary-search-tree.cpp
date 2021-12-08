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
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};

/*
bool isValidBST(TreeNode* root) {
        if(root==nullptr) return true;
        if(root->left==nullptr and root->right==nullptr) return true;
        if(root->left>root or root->right<root){
            return false;
        }
        
        bool ans = isValidBST(root->left);
        bool ans2 = isValidBST(root->right);
        
        if(ans==false or ans2==false) return false;
        return true;
    }
*/