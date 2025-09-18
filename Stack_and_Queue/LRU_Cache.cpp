class LRUCache {
public:
    class Node{
        public:
            int key;
            int val;
            Node *next;
            Node *prev;
        Node(int key_, int val_){
            key = key_;
            val = val_;
        }
    };
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int capacity;
    unordered_map<int, Node *> mpp;

    LRUCache(int cap) {
        capacity =cap;
        head->next = tail;
        tail->prev = head;
    }
    
    void insertAfterHead(Node * newnode) {
        Node * temp = head -> next;
        newnode -> next = temp;
        newnode -> prev = head;
        head -> next = newnode;
        temp -> prev = newnode;
    }

    void deleteNode(Node * delnode) {
        Node * delprev = delnode -> prev;
        Node * delnext = delnode -> next;
        delprev -> next = delnext;
        delnext -> prev = delprev;
    }


    int get(int key) {
        if(mpp.find(key) != mpp.end()){
            Node *node = mpp[key];
            int res = node->val;

            mpp.erase(key);
            deleteNode(node);
            insertAfterHead(node);
            mpp[key] = head->next;
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // if key is present
        if(mpp.find(key) != mpp.end()){
            Node *node = mpp[key];
            node->val = value;
            deleteNode(node);
            insertAfterHead(node);
            mpp[key] = head->next;
        }
        else{  // if key is not present
            // if size if full
            if(mpp.size() == capacity){
                Node *node = tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
            }
            // if size is not full
            Node *newNode = new Node(key, value);
            mpp[key] = newNode;
            insertAfterHead(newNode);
        }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
