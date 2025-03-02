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

//------------------------------- brute -------------------------------//

Node* startingPointOfCycle(Node *head){
	map<Node*, int> mpp;
	Node *temp = head;
	while(temp != NULL){
		if(mpp.find(temp) != NULL){
			return temp;
		}
		mpp[temp] = 1;
		temp = temp->next;
	}
	return NULL;
}

// ----------------------------- optimal -------------------------------//

Node* startingPointOfCycle(Node *head){
	Node *slow = head, *fast = head;
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast){
			slow = head;
			while(slow != fast){
				slow = slow->next;
				fast = fast->next;
			}
			return slow;
		}
	}

	return NULL;
}
