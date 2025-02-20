#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *next;
};

void recursiveTraversal(Node *head){
	if(head == NULL) return;
	cout<<head->data<<" ";
	recursiveTraversal(head->next);
}

int main(){
	struct Node *head;
	struct Node *second;
	struct Node *third;
	struct Node * fourth;

	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	fourth = (struct Node*)malloc(sizeof(struct Node));

	head->data = 7;
	head->next = second;

	second->data = 5;
	second->next = third;

	third->data = 3;
	third->next = fourth;

	fourth->data = 11;
	fourth->next = NULL;

	recursiveTraversal(head);
}
