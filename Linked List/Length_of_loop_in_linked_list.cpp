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

// ----------------------------------- brute -------------------------//

int countNodesinLoop(Node *head) {
    // Code here
    map<Node*, int> mpp;
    Node *temp = head;
    int timer = 1;
    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()){
            int value = mpp[temp];
            return (timer - value);
        }
        mpp[temp] = timer;
        timer++;
        temp = temp->next;
    }
    return 0;
}

// -------------------------------- optimal ---------------------------//

int findLength(Node *slow, Node *fast){
    int ct = 1;
    fast = fast ->next;
    while(slow != fast){
        ct++;
        fast = fast->next;
    }
    return ct;
}

int countNodesinLoop(Node *head) {
    // Write your code here
    Node *slow = head, *fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow ->next;
        fast = fast->next->next;
        if(slow == fast) return findLength(slow, fast);
    }
    return 0;
}
