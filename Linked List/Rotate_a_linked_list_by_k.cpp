Node *findNthNode(Node *temp, int n){
     int ct = 1;
     while(temp != NULL){
          if(ct == n) return temp;
          ct++;
          temp = temp->next;
     }
     return temp;
}

Node *rotate(Node *head, int k) {
     // Write your code here.
     if(head == NULL || k == 0) return head;

     // find length and tail
     int len = 1;
     Node *tail = head;

     while(tail->next != NULL){
          len++;
          tail = tail->next;
     }

     // check if k is a multiple of len
     if(k % len == 0) return head;

     // take modulo of len if k is greater than len
     k = k % len;

     // point tail's next to the head;
     tail->next = head;

     // find new LastNode;
     Node *newLastNode = findNthNode(head, len - k);

     // get the new head
     head = newLastNode->next;

     // point newLastNode's next to NULL
     newLastNode->next = NULL;

     return head;
}
