#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *next;
};

struct Node *deleteAtFirst(struct Node *head){
	struct Node *ptr = head;
	head = head->next;
	free(ptr);
	return head;
}

struct Node *deleteAtIndex(struct Node *head, int index){
	struct Node *p = head;
	struct Node *q = head->next;
	for(int i=0;i<index-1;i++){
		p = p->next;
		q = q->next;
	}
	p->next = q->next;
	free(q);
	return head;
}

struct Node *deleteAtLast(struct Node *head){
	struct Node *p = head;
	struct Node *q = head->next;

	while(q->next!=NULL){
		p = p->next;
		q = q->next;
	}
	p->next = NULL;
	free(q);
	return head;
}

struct Node *deleteWithGivenValue(struct Node *head, int value){
	struct Node *p = head;
	struct Node *q = head->next;
	while(q->data != value && q->next!=NULL){
		p = p->next;
		q = q->next;
	}
	if(q->data == value){
		p->next = q->next;
		free(q);
	}
	return head;
}



//Delete a node without head pointer.
void deleteNode(struct Node *del){
	if(del == NULL){
		return;
	}
	else{
		if(del->next == NULL){
			return;
		}
		struct Node *temp = del->next;
		del->data = temp->data;
		del->next = temp->next;
		free(temp);
	}
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
