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
    TreeNode* buildTree(vector<int>& preorder,int psi,int pei, vector<int>& inorder,int isi, int iei) {
        if(isi > iei) return nullptr;
        
        int idx = isi;
        while(inorder[idx] != preorder[psi]) idx++;
        
        int colse = idx-isi;
        
        TreeNode *node = new TreeNode(preorder[psi]);
        
        node->left = buildTree(preorder, psi+1, psi+colse, inorder, isi,idx-1);
        node->right = buildTree(preorder,psi+colse+1,pei, inorder, idx+1,iei);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        return buildTree(preorder,0,n-1,inorder,0,n-1);
    }
};