/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int data;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int val) { data = val; left = null, right = null }
 * }
 **/

class Solution {
    public List<Integer> preorder(TreeNode root) {
        //your code goes here
        // Preorder traversal: root -> left -> right;
        List<Integer> preorder = new ArrayList<Integer>();
        if(root == null) return preorder;

        Stack<TreeNode>st = new Stack<TreeNode>();
        st.push(root);

        while(!st.isEmpty()){
            // pop the root node
            root = st.pop();
            preorder.add(root.data);
            // push right into the stack at first (so we can access the left first)
            if(root.right != null) st.push(root.right);
            // push left (we will access it before right since it is above right in the stack)
            if(root.left != null) st.push(root.left);
        }
        return preorder;
    }
}
