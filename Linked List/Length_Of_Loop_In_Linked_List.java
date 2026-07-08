/*Definition of singly linked list:
class ListNode {
    int val;
    ListNode next;

    ListNode() {
        val = 0;
        next = null;
    }

    ListNode(int data1) {
        val = data1;
        next = null;
    }

    ListNode(int data1, ListNode next1) {
        val = data1;
        next = next1;
    }
}
 */

 class Solution {

     // brute force: TC = O(N), SC = O(N)
     public int findLengthOfLoop(ListNode head) {
        HashMap<ListNode, Integer> visitedNodes = new HashMap<>();

        // Pointer to traverse the linked list
        ListNode temp = head;

        // Timer to track visited nodes
        int timer = 0;

        // Traverse the linked list till temp reaches null
        while (temp != null) {
            // If revisiting a node, return the difference of timer values
            if (visitedNodes.containsKey(temp)) {
                // Calculate the length of the loop
                int loopLength = timer - visitedNodes.get(temp);

                // Return the length of the loop
                return loopLength;
            }

            // Store the current node and its timer value
            visitedNodes.put(temp, timer);

            // Move to the next node
            temp = temp.next;

            // Increment the timer
            timer++;
        }

        // If traversal is completed and we reach the end of the list
        // means there is no loop
        return 0;
     }

   // Optimal
   public int findLengthOfLoop(ListNode head) {
        ListNode slow = head, fast = head;
        while(fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;

            if(slow == fast){
                return countLoopLength(slow);
            }
        }
        return 0;
    }
    public int countLoopLength(ListNode head){
        int length = 1;
        ListNode temp = head;
        while(temp.next != head){
            length++;
            temp = temp.next;
        }
        return length;
    }
 }
