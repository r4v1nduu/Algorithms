#include <iostream>
using namespace std;

class StackX {
private:
    int maxSize;        // size of stack array
    double* stackArray; // stack array
    int top;            // top of the stack

public:
    // constructor
    StackX(int s) {
        maxSize = s;             // set array size
        stackArray = new double[maxSize];
        top = -1;                 // no items
    }

    // push operation
    void push(double j) {
        // check whether stack is full
        if (top == maxSize - 1)
            cout << "Stack is full" << endl;
        else
            stackArray[++top] = j;
        // increment top by 1, then insert j to the array-top location
    }

    // pop operation
    double pop() {
        if (top == -1)
            return -99;
        else
            return stackArray[top--];
        // decrement top by 1, then return the value at the array-top location
    }

    // peek operation
    double peek() {
        if (top == -1)
            return -99;
        else
            return stackArray[top];
        // return the value at the top index
    }

    // check if the stack is empty
    bool isEmpty() { return top == -1; }
    // check if the stack is full
    bool isFull() { return top == maxSize - 1; }

    // get the count of elements in the stack
    int getCount() { return top + 1; }

    // destructor
    ~StackX() {
        delete[] stackArray; // release memory
    }
};

int main() {
    StackX MyStack(10);

    MyStack.push(10);
    MyStack.push(20);
    MyStack.push(30);

    cout << MyStack.getCount() << endl;

    while (!MyStack.isEmpty()) {
        double temp = MyStack.pop();
        cout << temp << endl;
    }

    cout << MyStack.getCount() << endl;

    return 0;
}
