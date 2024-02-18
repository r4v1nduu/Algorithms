class QueueX {
    private int maxSize;    // size of queue array
    private int [] queArray;
    private int front;      //front of the queue 
    private int rear;       //rear of the queue
    private int nItems;     //no of items of the queue

    private int temp;

    public QueueX (int s) {
        maxSize = s;        // set array size
        queArray = new int [maxSize];
        front = 0;          //front index
        rear = -1;          //rear index
        nItems = 0;         //number of items
    }

    public void insert(int j) {
        // check whether all slots in circular queue is filled
        if (nItems == maxSize)
               System.out.println("Queue is full");
        else {
            if (rear == maxSize - 1) {
                rear = -1;
                //reset rear to -1, if rear is at the end of the array (next rear will be at 0)
            }
            queArray[++rear] = j;
            //increment rear by 1, then insert j to the array-rear location
            nItems++;
        }
    }
    
    public int remove() { 
        if (nItems == 0) {
            System.out.println("Queue is empty");
            return -99;
        }
        else { 
            temp = queArray[front++];   //get value and increment front
            if (front == maxSize) {
                front = 0;
                //reset front to 0, if front is at the end of the array (next front will be at 0)
            }
            nItems--;
            return temp;
        }
    }

    public int peekFront() { 
        if (nItems == 0) {
            System.out.println("Queue is empty");
            return -99; 
        }
        else {
            return queArray[front]; 
            //return the value at the front index
        }
    }

    public boolean isEmpty() {
        if (nItems == 0) 
            return true;
        else 
            return false;
    }

    public boolean isFull() {
        if (nItems == maxSize)
            return true;
        else
            return false;
    }

}