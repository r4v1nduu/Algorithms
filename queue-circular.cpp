#include <iostream>

class QueueX {
private:
    int maxSize;    // size of queue array
    int* queArray;  // queue array
    int front;       // front of the queue
    int rear;        // rear of the queue
    int nItems;      // number of items in the queue

    int temp;        // temporary variable
public:
    int tempClear;   // public variable for clearing temp

    // constructor
    QueueX(int s) {
        maxSize = s;             // set array size
        queArray = new int[maxSize];
        front = 0;                // front index
        rear = -1;                // rear index
        nItems = 0;               // number of items
    }

    // insert operation for circular queue
    void insert(int j) {
        // check whether all slots in the circular queue are filled
        if (nItems == maxSize)
            std::cout << "Queue is full" << std::endl;
        else {
            if (rear == maxSize - 1) {
                rear = -1;
                // reset rear to -1 if rear is at the end of the array (next rear will be at 0)
            }
            queArray[++rear] = j;  // increment rear by 1, then insert j to the array-rear location
            nItems++;
        }
    }

    // remove operation for circular queue
    int remove() {
        if (nItems == 0) {
            std::cout << "Queue is empty" << std::endl;
            return -99;
        } else {
            temp = queArray[front++];  // get value and increment front
            if (front == maxSize) {
                front = 0;
                // reset front to 0 if front is at the end of the array (next front will be at 0)
            }
            nItems--;
            return temp;
        }
    }

    // peekFront operation
    int peekFront() {
        if (nItems == 0) {
            std::cout << "Queue is empty" << std::endl;
            return -99;
        } else {
            return queArray[front];
            // return the value at the front index
        }
    }

    // check if the queue is empty
    bool isEmpty() {
        return nItems == 0;
    }

    // check if the queue is full
    bool isFull() {
        return nItems == maxSize;
    }

    // destructor
    ~QueueX() {
        delete[] queArray; // release memory
    }
};

class UseQueue {
public:
    static void main() {
        QueueX MyQueue(10);

        MyQueue.insert(10);
        MyQueue.insert(25);
        MyQueue.insert(55);
        MyQueue.insert(65);
        MyQueue.insert(85);

        while (!MyQueue.isEmpty()) {
            int tempClear = MyQueue.remove();
            std::cout << tempClear << std::endl;
        }
    }
};

int main() {
    QueueX MyQueue(10);

    MyQueue.insert(10);
    MyQueue.insert(25);
    MyQueue.insert(55);
    MyQueue.insert(65);
    MyQueue.insert(85);

    while (!MyQueue.isEmpty()) {
        int tempClear = MyQueue.remove();
        std::cout << tempClear << std::endl;
    }

    return 0;
}
