class LRUCache {
public:
    class Node {
        public:
        int key;
        int val;
        Node* next = NULL;
        Node* prev = NULL;

        Node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int size;
    unordered_map<int, Node*> mpp;

    void addNode(Node* node){
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }

    void deleteNode(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }


    LRUCache(int capacity) {
        size = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            Node* currNode = mpp[key];
            int currVal = currNode->val;
            mpp.erase(key);
            deleteNode(currNode);
            addNode(currNode);
            mpp[key] = head->next;
            return currVal;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* currNode = mpp[key];
            mpp.erase(key);
            deleteNode(currNode);
        }
        if(mpp.size()==size){
            mpp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        mpp[key] = head->next;
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */