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
    void depth(TreeNode *root, int &count){
        if(root==NULL) return;
        count=std::max(maxDepth(root->left),maxDepth(root->right))+1;
    }
    int maxDepth(TreeNode* root) {
        int count=0;
        depth(root,count);
        return count;
    }
};