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


// -------------------------------- brute -----------------------------//

bool hasCycle(Node *head){
	map<Node*, int> mpp;
	Node *temp = head;
	while(temp != NULL){
		if(mpp.find(temp) != mpp.end()) return true;
		mpp[temp] = 1;
		temp = temp->next;
	}
	return false;
}


// -------------------------------- optimal ---------------------------//

bool hasCycle(Node * head){
	Node *slow = head, *fast = head;
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next;
		if(slow == fast) return true;
	}
	return false;
}
