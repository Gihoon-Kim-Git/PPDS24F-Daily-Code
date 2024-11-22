#include <iostream>
#include <vector>

using namespace std;

class MyStack {
    public:
        int size; //⭐
        int capacity;//⭐
        vector<int> arr;//⭐ 여기서 선언해줘야 밑에서 생성하면서 초기화

        MyStack() {
            size = 0;
            capacity = 100;
            arr = vector<int>(capacity, -1);
        }
        
        void push(int x) {
            arr[size] = x;
            size++;
        }
        
        int pop() {
            int ele = arr[size-1];
            size--;
            return ele;
        }
        
        int top() {
            return arr[size-1];
        }
        
        bool empty() {
            return size==0;
        }

        void print() {
            for (int i=0; i < size; i++) {cout<< arr[i] << " ";}
            cout << endl;
        }
};

int main() {
    MyStack* obj = new MyStack();
    cout << obj->empty() << endl;

    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->print();

    cout << obj->pop() << endl;
    cout << obj->top() << endl;
    cout << obj->pop() << endl;
    obj->print();
    cout << obj->pop() << endl;
    cout << obj->empty() << endl;
    obj->push(3);
    return 0;
}

