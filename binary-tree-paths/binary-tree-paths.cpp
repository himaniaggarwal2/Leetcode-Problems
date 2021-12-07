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
    vector<string> result;
    void path (TreeNode* head,string paths){
        if(head==nullptr) return;
        if(head->left==nullptr and head->right==nullptr){
            result.push_back(paths);
            return;
        }
        if(head->left)  path(head->left,paths+"->"+to_string(head->left->val));
        if(head->right) path(head->right,paths+"->"+to_string(head->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return result;
        TreeNode* head=root;
        path(head,to_string(head->val));
        return result;
    }
};