#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node *next;
};


struct Node *insertAtFirst(struct Node *head, int data){
	struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->next = head;
	ptr->data = data;
	return ptr;
}

struct Node *insertAtIndex(struct Node *head, int data, int index){
	struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
	struct Node *p = head;
	int i=0;
	while(i!=index-1){
		p = p->next;
		i++;
	}
	ptr->data = data;
	ptr->next = p->next;
	p->next = ptr;
	return head;
}

struct Node *insertAtEnd(struct Node *head, int data){
	struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data = data;

	struct Node *p = head;
	while(p->next!=NULL){
		p = p->next;
	}
	p->next = ptr;
	ptr->next = NULL;
	return head;
}

struct Node *insertAfter(struct Node *head, struct Node *prevNode, int data){
	struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data = data;
	ptr->next = prevNode->next;
	prevNode->next = ptr;
	return head;
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

	

}
