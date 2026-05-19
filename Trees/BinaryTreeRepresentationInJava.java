package org.Practice.DSA.Trees.BinaryTreeRepresentationInJava;

class Node {
    int data;
    Node left;
    Node right;

    public Node(int key){
        this.data = key;
    }
}

public class BinaryTreeRepresentationInJava {
    public static void main(String[] args) {

        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.right.left = new Node(5);

        /* below tree structure is formed
        *         1
        *       /   \
        *     2       3
        *           /
        *         5
        * */

    }
}
