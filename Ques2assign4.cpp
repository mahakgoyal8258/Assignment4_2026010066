
#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue
{
    int arr[MAX];
    int front, rear;

public:
    CircularQueue()
    {
        front = rear = -1;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    bool isFull()
    {
        return (rear + 1) % MAX == front;
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue Overflow\n";
            return;
        }

        if (isEmpty())
            front = 0;

        rear = (rear + 1) % MAX;
        arr[rear] = x;

        cout << "Element inserted\n";
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow\n";
            return;
        }

        cout << "Deleted: " << arr[front] << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }

    void peek()
    {
        if (isEmpty())
            cout << "Queue is empty\n";
        else
            cout << "Front element: " << arr[front] << endl;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }

        int i = front;

        while (true)
        {
            cout << arr[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }

        cout << endl;
    }
};

int main()
{
    CircularQueue q;
    int choice, x;

    do
    {
        cout << "\n1.Enqueue  2.Dequeue  3.isEmpty";
        cout << "\n4.isFull   5.Display  6.Peek  0.Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element: ";
            cin >> x;
            q.enqueue(x);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            cout << (q.isEmpty() ? "Queue is empty" :
                     "Queue is not empty") << endl;
            break;

        case 4:
            cout << (q.isFull() ? "Queue is full" :
                     "Queue is not full") << endl;
            break;

        case 5:
            q.display();
            break;

        case 6:
            q.peek();
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}

