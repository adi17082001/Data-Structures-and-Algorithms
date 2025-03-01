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


// ---------------- iterative ------------------------------------//

Node* reverse_iterative(Node *head){
	Node *temp = head;
	Node *prev = NULL;

	while(temp != NULL){
		Node *front = temp->next;
		temp->next = prev;
		prev = temp;
		temp = front;
	}
	return prev;
}


//-------------------------------------- recursive ---------------------------------//

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

int main(){
	Node *head = new Node(1);
	Node *second = new Node(2);
	Node *third = new Node(3);
	Node *fourth = new Node(4);
	Node *fifth = new Node(5);

	head->next = second;
	second->next = third;
	third->next = fourth;
	fourth->next = fifth;
	fifth->next = NULL;

	Node *newHead = reverse(head);

	Node *curr = newHead;
	for(curr = newHead; curr != NULL; curr= curr->next){
		cout << curr->data << " ";
	}

}
