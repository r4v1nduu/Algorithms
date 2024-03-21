package Java;
import java.util.Scanner;

public class QueueX {
    private int[] QueueArr; // array to hold the queue
    private int maxSize;    // size of the queue array
    private int front;      // front of the queue
    private int rear;       // rear of the queue
    private int nItems;     // number of items in the queue

    // constructor to initialize the queue
    public QueueX(int s) {
        maxSize = s;
        QueueArr = new int[maxSize];
        front = 0;
        rear = -1;
        nItems = 0;
    }

    // method to insert an element to the queue
    public void insert(int j) {
        // check whether queue is full
        if (rear == maxSize - 1) {
            System.out.println("Queue is full");
        }
        else {
            QueueArr[++rear] = j;   // increment rear and insert
            nItems++;               // increase the number of items
        }
    }

    // method to remove an element from the queue
    public int remove() {
        // check whether queue is empty
        if (nItems == 0) {
            System.out.println("Queue is empty");
            return -99;
        }
        else {
            nItems--;                   // decrease the number of items
            return QueueArr[front++];   // get value and increment front
        }
    }

    // method to check if the queue is empty
    public boolean isEmpty() {
        return (nItems == 0);
    }

    // method to check if the queue is full
    public boolean isFull() {
        return (rear == maxSize - 1);
    }
}

class MainQueue {
    public static void main(String[] args) {
        QueueX mainQueue = new QueueX(5);
        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < 5; i++) {
            System.out.print("Enter a number: ");
            mainQueue.insert(sc.nextInt());
        }
    }

    //Create separate queues to store even and odd transaction IDs
    QueueX evenQueue = new QueueX(5);
    QueueX oddQueue = new QueueX(5);

    //Separate the transaction IDs into even and odd queues
    public int value;
    while (!mainQueue.isEmpty()) {
        value = MainQueue.remove();
        if (value % 2 == 0) {
            evenQueue.insert(value);
        }
        else {
            oddQueue.insert(value);
        }
    }

    //Process even queue
    System.out.println("Even Queue: ");
    while (!evenQueue.isEmpty()) {
        System.out.println("Transaction: "+evenQueue.remove());
    }
    System.out.println("Odd Queue: ");
    while (!oddQueue.isEmpty()) {
        System.out.println("Transaction: "+oddQueue.remove());
    }
}
