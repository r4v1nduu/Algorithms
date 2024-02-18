class QueueX {
    private int maxSize;    // size of queue array
    private int [] queArray;
    private int front;      //front of the queue 
    private int rear;       //rear of the queue
    private int nItems;     //no of items of the queue

    public QueueX (int s) {
        maxSize = s;        // set array size
        queArray = new int [maxSize];
        front = 0;          //front index
        rear = -1;          //rear index
        nItems = 0;         //number of items
    }

    public void insert(int j) {
        // check whether queue is full
        if (rear == maxSize - 1)
        //(-1), because array indexing starts with 0
               System.out.println("Queue is full");
        else {
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
            nItems--;   //decrement nItems
            return queArray[front++];   //get value and increment front
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
    
    //test


}