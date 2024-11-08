class LRUCache {
public:
class Node{
        public:
            int val;
            int key;
            Node* next;
            Node* prev;

            Node(int _key, int _val){
                key = _key;
                val = _val;
            }
    };
unordered_map<int,Node* >mpp;
int cap;
 Node* head=new Node(-1,-1);
Node* tail= new Node(-1,-1);

void deleteNode(Node* node) {

		// Get the previous and next pointers
		Node* prevNode = node-> prev;
		Node* nextNode = node-> next;

		// Remove pointers to node
		prevNode-> next = nextNode;
		nextNode-> prev = prevNode;
	}


void insertAfterHead(Node* node) {

		Node* nextNode = head-> next;
        head-> next = node;
nextNode-> prev = node;
		node-> prev = head;
		node-> next = nextNode;
	}


    LRUCache(int capacity) {
         cap=capacity;
         mpp.clear();
        head->next=tail;
        tail->prev=head;
     }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        Node* node=mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
         if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            node->val=value;
            deleteNode(node);
            insertAfterHead(node);
            return;
         }
         else{
            if(mpp.size()==cap){
                Node * node=tail->prev;
                mpp.erase(node->key);
                deleteNode(node);
            }
         }
         Node* newNode=new Node(key,value);
         mpp[key]=newNode;
         insertAfterHead(newNode);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */