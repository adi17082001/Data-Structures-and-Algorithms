class Node {
    int data;
    Node left;
    Node right;

    // Constructor to initialize the node with a value
    public Node(int val) {
        data = val;
        left = null;
        right = null;
    }
}

class Solution {

    // Function to return the postOrder traversal of a binary tree using one stack
    public static java.util.List<Integer> postOrder(Node root) {
        java.util.List<Integer> postorder = new java.util.ArrayList<>();  // List to store the postorder traversal

        // Check if the tree is empty, return an empty result
        if (root == null) {
            return postorder;
        }

        java.util.Stack<Node> st = new java.util.Stack<>();  // Stack to store nodes during traversal
        Node curr = root;

        // Traverse the tree until current node is null or the stack is empty
        while (curr != null || !st.isEmpty()) {
            // If current node is not null, push it onto the stack and move to its left child
            if (curr != null) {
                st.push(curr);
                curr = curr.left;
            } else {
                // If current node is null, check the right child of the top node in the stack
                Node temp = st.peek().right;

                // If right child is null or already visited, process the top node
                if (temp == null) {
                    temp = st.pop();
                    postorder.add(temp.data);  // Add the node's data to the postorder result

                    // Check if there are more nodes to pop whose right subtree is also processed
                    while (!st.isEmpty() && temp == st.peek().right) {
                        temp = st.pop();
                        postorder.add(temp.data);
                    }
                } else {
                    // If right child exists, set current node to the right child
                    curr = temp;
                }
            }
        }

        // Return the postorder traversal result
        return postorder;
    }
}

public class Main {

    public static void main(String[] args) {
        // Creating a sample binary tree
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);

        // Getting the postorder traversal
        java.util.List<Integer> result = Solution.postOrder(root);

        // Printing the postorder traversal result
        System.out.print("Postorder traversal: ");
        for (int val : result) {
            System.out.print(val + " ");
        }
        System.out.println();
    }
}
