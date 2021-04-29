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
    public int indexPre = 0;
    
    public TreeNode buildTree(int[] preorder, int[] inorder, int st, int dr) {
        if(st>dr)
            return null;
         
        TreeNode root = new TreeNode(preorder[indexPre], null, null);
        indexPre++;
        
        //cautare in inorder
        int i, n=inorder.length;
        for(i=0;i<n;i++)
            if(inorder[i] == root.val)
                break;
        
        root.left = buildTree(preorder, inorder, st, i-1);
        root.right = buildTree(preorder, inorder, i+1, dr);
        return root;
    }
    
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        indexPre = 0;
        return buildTree(preorder, inorder, 0, inorder.length-1);
    }
    

}