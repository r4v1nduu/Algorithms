#include <iostream>

class QueueX {
private:
    int maxSize;    // size of queue array
    int* queArray;  // queue array
    int front;       // front of the queue
    int rear;        // rear of the queue
    int nItems;      // number of items in the queue

public:
    // constructor
    QueueX(int s) {
        maxSize = s;             // set array size
        queArray = new int[maxSize];
        front = 0;                // front index
        rear = -1;                // rear index
        nItems = 0;               // number of items
    }

    // insert operation
    void insert(int j) {
        // check whether queue is full
        if (rear == maxSize - 1)
            std::cout << "Queue is full" << std::endl;
        else {
            queArray[++rear] = j;  // increment rear by 1, then insert j to the array-rear location
            nItems++;
        }
    }

    // remove operation
    int remove() {
        if (nItems == 0) {
            std::cout << "Queue is empty" << std::endl;
            return -99;
        } else {
            nItems--;                    // decrement nItems
            return queArray[front++];    // get value and increment front
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

int main() {
    QueueX MyQueue(5);

    MyQueue.insert(10);
    MyQueue.insert(20);
    MyQueue.insert(30);

    std::cout << "Front element: " << MyQueue.peekFront() << std::endl;

    while (!MyQueue.isEmpty()) {
        int temp = MyQueue.remove();
        std::cout << temp << " ";
    }

    std::cout << std::endl;

    return 0;
}
