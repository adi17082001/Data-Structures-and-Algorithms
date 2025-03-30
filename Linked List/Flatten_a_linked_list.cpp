// Brute -

/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid);  // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);  // merging sorted halves
}

Node *convert(vector<int>&arr){
    if(arr.size() == 0) return NULL;
    Node *head = new Node(arr[0]);
    Node *temp = head;
    for(int i = 1; i < arr.size(); i++){
        Node *newNode = new Node(arr[i]);
        temp->child = newNode;
        temp = temp->child;
    }
    return head;
}

Node* flattenLinkedList(Node* head) 
{
	// Write your code here
    vector<int>arr;
    Node *temp = head;
    while(temp != NULL){
        Node *t2 = temp;
        while(t2 != NULL){
            arr.push_back(t2->data);
            t2 = t2->child;
        }
        temp = temp->next;
    }
    mergeSort(arr, 0, arr.size()-1);
    head = convert(arr);

    return head;
}



// optimized

Node* merge(Node *list1, Node *list2){
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;
    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else{
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = NULL;
    }
    if(list1) res->child = list1;
    else res->child = list2;

    return dummyNode->child;
}

Node* flattenLinkedList(Node* head) 
{
	if(head == NULL || head->next == NULL) return head;

    Node *mergedHead = flattenLinkedList(head->next);

    return merge(head, mergedHead);
}
