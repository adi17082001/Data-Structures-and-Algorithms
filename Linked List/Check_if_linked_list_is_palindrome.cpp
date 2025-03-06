#include<bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *next;

    // Default constructor
    Node() {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

//---------------------- brute ------------------------------------//

bool isPalindrome(Node* head) {
    stack<int>st;
    Node *temp = head;
    while(temp != NULL){
        st.push(temp->val);
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL){
        if(temp->val != st.top()) return false;
        temp = temp->next;
        st.pop();
    }
    return true;
}


//--------------------------- optimal --------------------------------//

Node *reverseLinkedList(Node *head){
	if(head == NULL || head->next == NULL) return head;
	Node *newHead = reverseLinkedList(head->next);
	Node *front = head->next;
	front->next = head;
	head->next = NULL;
	return newHead;
}

bool isPalindrome(Node *head){
	if(head == NULL || head->next == NULL) return head;

	Node *slow = head;
	Node *fast = head;
	while(fast->next != NULL && fast->next->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	Node *newHead = reverseLinkedList(slow->next);
	Node *first = head;
	Node *second = newHead;
	while(second != NULL){
		if(first->data != second->data){
			reverseLinkedList(newHead);
			return false;
		}
		first = first->next;
		second = second->next;
	}
	reverseLinkedList(newHead);
	return true;

}
