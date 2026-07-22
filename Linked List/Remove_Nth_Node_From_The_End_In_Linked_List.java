// brute
public ListNode removeNthFromEnd(ListNode head, int n) {
        // If list is empty
        if (head == null) {
            return null;
        }

        int cnt = 0;
        ListNode temp = head;

        // Count total number of nodes
        while (temp != null) {
            cnt++;
            temp = temp.next;
        }

        // If N equals total nodes → delete head
        if (cnt == n) {
            return head.next;
        }

        // Calculate position from start
        int res = cnt - n;
        temp = head;

        // Traverse to the node before target
        while (temp != null) {
            res--;
            if (res == 0) {
                break;
            }
            temp = temp.next;
        }

        // Delete the node
        temp.next = temp.next.next;

        return head;
    }
// optimal
public ListNode removeNthFromEnd(ListNode head, int n) {
        // Create a dummy node before head to handle edge cases
        ListNode dummy = new ListNode(0, head);

        // Initialize slow and fast pointers at dummy
        ListNode slow = dummy, fast = dummy;

        // Move fast pointer N+1 steps ahead to create a gap
        for(int i = 0; i <= n; i++){
            fast = fast.next;
        }

        // Move both pointers until fast reaches the end
        while(fast != null){
            slow = slow.next;
            fast = fast.next;
        }

        // Slow is now at node before target → delete target node
        slow.next = slow.next.next;

         // Return updated head
        return dummy.next;
    }
