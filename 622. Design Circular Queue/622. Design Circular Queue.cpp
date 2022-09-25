//Author: Devendra Uraon
class MyCircularQueue {
public:
    vector<int> v;
    int front, size, cap, rear;

    MyCircularQueue(int k) {
        for(int i = 0; i < k; i++) v.push_back(-1);
        front = 0;
        rear = -1;
        size = k;
        cap = 0;
    }

    bool enQueue(int value) {
        if(!isFull()){
        rear++;
        rear = rear % size;
        v[rear] = value;
        cap++;
        return true;
        }
        else return false;

    }

    bool deQueue() {
        if(!isEmpty()){
            v[front] = -1;
            front++;
           front = front % size;
            cap--;
            return true;
        }
        else return false;


    }

    int Front() {
        return v[front];
    }

    int Rear() {
        if(isEmpty()) return -1;
        else return v[rear];
    }

    bool isEmpty() {
        if(cap == 0) return true;
        else return false;


    }

    bool isFull() {
        if(cap == size) return true;
        else return false;
    }
};