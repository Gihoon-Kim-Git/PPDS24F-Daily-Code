#include <stdio.h>
#include <stdbool.h>


typedef struct {
    int maxsize;
    int* num;
    int size;
} MyCircularDeque;


MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque* z = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    
    z->maxsize = k;
    z->num = (int*)calloc(k, sizeof(int));
    z->size = 0;
    return z;
}

bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if(obj->size == obj->maxsize){
        return false;
    }
    else{
        for (int i = obj->size; i > 0; i--) {
            obj->num[i] = obj->num[i - 1];
        }
        obj->num[0] = value;
        obj->size++;
        return true;
    }
}

bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if(obj->size == obj->maxsize){
        return false;
    }
    else{
        obj->num[obj->size] = value;
        obj->size++;
        return true;
    }
}

bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if(obj->size == 0){
        return false;
    }
    else{
        for (int i = 0; i < obj->size-1; i++) {
            obj->num[i] = obj->num[i + 1];
        }
        obj->size--;
        obj->num[obj->size] = 0;
        return true;
    }
}

bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if(obj->size == 0){
        return false;
    }
    else{
        obj->num[obj->size-1] = 0;
        obj->size--;
        return true;
    }
}

int myCircularDequeGetFront(MyCircularDeque* obj) {
    if(obj->size == 0){
        return -1;
    }
    else{
        return obj->num[0];
    }
}

int myCircularDequeGetRear(MyCircularDeque* obj) {
    if(obj->size == 0){
        return -1;
    }
    else{
        return obj->num[obj->size-1];
    }
}

bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}

bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->size == obj->maxsize;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj);
}

int main(void){
    MyCircularDeque* obj = myCircularDequeCreate(3);
    bool param_1 = myCircularDequeInsertFront(obj, 1);

    bool param_2 = myCircularDequeInsertLast(obj, 3);

    myCircularDequeFree(obj);

    return 0;
}