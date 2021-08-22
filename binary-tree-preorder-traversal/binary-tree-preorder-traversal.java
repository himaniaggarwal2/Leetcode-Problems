/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> ans= new ArrayList<>();
        
        while(root!=null){
            if(root.left == null){
                ans.add(root.val);
                root=root.right;
            }else{
                TreeNode rootplusone = root.left;
                while(rootplusone.right != null && rootplusone.right != root){
                    rootplusone=rootplusone.right;
                }
                if(rootplusone.right == null){
                    //1st iteration
                    ans.add(root.val);
                    rootplusone.right=root;
                    root=root.left;
                }
                else{
                    //2nd iteration
                    rootplusone.right= null;
                    root=root.right;
                }
            }
        }
        return ans;
    }
}