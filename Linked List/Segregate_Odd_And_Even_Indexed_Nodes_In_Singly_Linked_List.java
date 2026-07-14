/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        //YOUR CODE GOES HERE
        if(head == null || head.next == null) return head;

        List<Integer>array = new ArrayList<>();

        ListNode temp = head;

        // store odd indexed nodes
        while(temp != null && temp.next != null){
            array.add(temp.val);
            temp = temp.next.next;
        }
        // if traversal ends on a valid odd-indexed node, add it too
        if(temp != null) array.add(temp.val);

        // reset temp
        temp = head.next;

        // store even indexed nodes
        while(temp != null && temp.next != null){
            array.add(temp.val);
            temp = temp.next.next;
        }
        // if traversal ends on a valid even indexed node, add it too
        if(temp != null) array.add(temp.val);

        // reset temp;
        temp = head;
        int i = 0;

        // update node values
        while(temp != null){
            temp.val = array.get(i);
            temp = temp.next;
            i++;
        }
        return head;
    }
}
