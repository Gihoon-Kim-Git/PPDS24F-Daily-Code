struct Node {
    int data;
    Node * next, * last; 

    Node(int x, Node* next = nullptr, Node* last = nullptr): data(x), next(next), last(last) {}
};

class MyCircularDeque {
    Node* dummy; 
    int k;
    int len;

public:
    MyCircularDeque(int k) : k(k), len(0) { 
        dummy = new Node(-1); 
        dummy->next = dummy->last = dummy;
    }
    
    bool insertFront(int value) {  
        if (len == k) return 0; 

        Node* newNode = new Node(value, dummy->next, dummy);
        dummy->next->last = newNode; 
        dummy->next = newNode;

        if (len == 0) {
            dummy->last = newNode;
        }
        len++;
        return 1;
    }
    
    bool insertLast(int value) { 
        if (len == k) return 0; 

        Node* newNode = new Node(value, dummy, dummy->last);
        dummy->last->next = newNode;
        dummy->last = newNode;

        if (len == 0) {
            dummy->next = newNode;
        }
        len++;
        return 1;
    }
    
    bool deleteFront() { // deletes an item from the front of Deque. 
    // returns true if the op is successful, or false ow
        if (len == 0) return 0; // empty

        Node* curr = dummy->next;
        dummy->next = curr->next;
        curr->next->last = dummy;

        delete curr;
        len--;

        return 1;
    }
    
    bool deleteLast() { 
        if (len == 0) return 0;

        Node* curr = dummy->last;
        dummy->last = curr->last;
        curr->last->next = dummy;

        delete curr;
        len--;

        return 1;
    }
    
    int getFront() { 
        return (len == 0) ? -1 : dummy->next->data;
    }
    
    int getRear() { 
        return (len == 0) ? -1 : dummy->last->data;
    }
    
    bool isEmpty() { 
        return len == 0;
    }
    
    bool isFull() { 
        return len == k;
    }
};