class MyCircularDeque {
public:
    vector<int> queue;
    int cur_size=0;
    int size;

    MyCircularDeque(int k) {
        size=k;
        queue.resize(k+1, -1);
    }
    
    bool insertFront(int value) {
        if(cur_size==size){
            return false;
        }

        for(auto i=cur_size; i>0; i--){
            queue[i]=queue[i-1];
        }
        queue[0]=value;
        cur_size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(cur_size==size){
            return false;
        }

        queue[cur_size]=value;
        cur_size++;
        return true;
    }
    
    bool deleteFront() {
        if(cur_size==0){
            return false;
        }
        for(auto i=0; i<cur_size-1; i++){
            queue[i]=queue[i+1];
        }
        queue[cur_size-1]=-1;
        cur_size--;
        return true;
    }
    
    bool deleteLast() {
        if(cur_size==0){
            return false;
        }
        queue[cur_size-1]=-1;
        cur_size--;
        return true;
    }
    
    int getFront() {
        return queue[0];
    }

    //cur_size==0일 때 인덱스 overflow 에러가 생기는 문제가 있었음
    int getRear() {
        if(cur_size==0){
            return queue[0];
        }
        return queue[cur_size-1];
    }
    
    bool isEmpty() {
        if(cur_size==0){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(cur_size!=size){
            return false;
        }
        return true;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */