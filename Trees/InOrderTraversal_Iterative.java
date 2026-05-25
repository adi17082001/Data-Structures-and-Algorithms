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
    public List<Integer> inorderTraversal(TreeNode root) {
        // declare the list to return as a result
        List<Integer> inorder = new ArrayList<>();
        // declare a stack to store the nodes (similar to auxiliary stack in recursive code)
        Stack<TreeNode> stack = new Stack<>();
        // start with the root node
        TreeNode node = root;

        // start the loop for inorder traversal
        while(true){
            if(node != null){
                stack.push(node);
                node = node.left;
            }
            else{
                // if stack is empty, it means we are on a leaf node and have reached the end of tree
                if(stack.isEmpty()) break;
                // if stack is not empty, it means we are on a leaf node and there are other nodes remaining to be traversed.
                // pop the top of stack, push it in the list
                node = stack.pop();
                inorder.add(node.val);
                // then move right
                node = node.right;
            }
        }
        return inorder;
    }
}
