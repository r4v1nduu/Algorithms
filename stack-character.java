class StackX {
    private int maxSize;    // size of stack array
    private char[] stackArray;
    private int top;           //top of the stack

    public StackX (int s) {   // constructor     
        maxSize = s;       // set array size
        stackArray = new char[maxSize];
        top = -1;             // no items
    }

    public void push(char j) {
        // check whether stack is full
        if (top == maxSize - 1)
            System.out.println("Stack is full");
        else
            stackArray[++top] = j;
            //increment top by 1, then insert j to the array-top location
    }

    public char pop() {
        if (top == -1)
            return '0';
        else
            return stackArray[top--];
            //decrement top by 1, then return the value at the array-top location
    }
    
    public char peek() {
        if (top == -1)
            return '0';
        else
            return stackArray[top];
            //return the value at the top index
    }
    
    public boolean isEmpty() {
        if (top == -1)
            return true;
        else
            return false;
    }

    public boolean isFull() {
        if (top == maxSize - 1)
            return true;
        else
            return false;
    }

    public int getCount() {
        return top + 1;
    }
}

class UseStack {
    public static void main(String[] args) {
        StackX MyStack = new StackX(10);

        MyStack.push('A');
        MyStack.push('B');
        MyStack.push('C');

        while (!MyStack.isEmpty()) {
            char temp = MyStack.pop();
            System.out.println(temp);
        }
    }
}

