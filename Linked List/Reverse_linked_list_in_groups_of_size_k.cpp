

Node *reverse(Node *head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	Node *newHead = reverse(head->next);
	Node *front = head->next;
	front->next = head;
	head->next = NULL;

	return newHead;
}

Node *findKthNode(Node *temp, int k){
    k = k - 1;
    while(temp != NULL && k > 0){
        k--;
        temp = temp->next;
    }
    return temp;
}

Node* kReverse(Node* head, int k) {
    // Write your code here.
    Node* temp = head, *prevNode = NULL;
    while(temp != NULL){
        Node *kthNode = findKthNode(temp, k);
        if(kthNode == NULL){
            if(prevNode) prevNode->next = temp;
            break;
        }
        Node *nextNode = kthNode->next;
        kthNode->next = NULL;
        reverse(temp);
        if(temp == head) head = kthNode;
        else{
            prevNode->next = kthNode;
        }
        prevNode = temp;
        temp = nextNode;
    }
    return head;
}
