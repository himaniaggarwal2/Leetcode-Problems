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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result={};
        if(root==nullptr) return result;
        queue<TreeNode*> que;
        que.push(root);
        while(que.size()>0){
            int count=que.size();
            while(count-->1){
                root=que.front();
                if(root->left!=nullptr){
                    que.push(root->left);
                }
                if(root->right!=nullptr){
                    que.push(root->right);
                }
                que.pop();
            }
            root=que.front();
            if(root->left!=nullptr){
                que.push(root->left);
            }
            if(root->right!=nullptr){
                que.push(root->right);
            }
            result.push_back(root->val);
            que.pop();
        }
        return result;
    }
};