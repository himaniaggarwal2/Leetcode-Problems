//https://practice.geeksforgeeks.org/problems/inorder-traversal/

class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    void inorderUtil(Node *root, vector<int> &vi)
    {
        if(root==NULL)  return;
        
        inorderUtil(root->left,vi);
        vi.push_back(root->data);
        inorderUtil(root->right,vi);
    }
    
    
    vector<int> inOrder(Node* root)
    {
        vector <int> vi;
        inorderUtil(root,vi);
        
        return vi;
    }
};