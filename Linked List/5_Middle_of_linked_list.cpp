// --------------------- brute -----------------------------------//

ListNode* middleNode(ListNode* head) {
    int ct = 0;
    ListNode *temp = head;
    while(temp != NULL){
        ct++;
        temp = temp->next;
    }
    int midNode = (ct/2) + 1;
    temp = head;
    while(temp != NULL){
        midNode = midNode - 1;
        if(midNode == 0){
            break;
        }
        temp = temp -> next;
    }
    return temp;
}


//----------------- optimal ----------------------------------//
// tortoise and hare algorithm

ListNode *middleNode(ListNode *head){
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
