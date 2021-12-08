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
    int tilt=0;
    int til(TreeNode* root){
       if(root==nullptr) return 0;
        
        int ls = til(root->left);
        int rs = til(root->right);
        
        int ltilt= abs(ls-rs);
        tilt+=ltilt;
        
        int ts = ls+rs+root->val;
        return ts; 
    }
    int findTilt(TreeNode* root) {
        if(root==nullptr) return 0;
        int result=til(root);
        return tilt;
    }
};