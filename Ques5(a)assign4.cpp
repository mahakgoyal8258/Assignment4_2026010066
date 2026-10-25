

#include <iostream>
#include <queue>
using namespace std;

class Stack
{
    queue<int> q1, q2;

public:
    void push(int x)
    {
        q2.push(x);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);

        cout << "Element pushed\n";
    }

    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack Underflow\n";
            return;
        }

        cout << "Popped: " << q1.front() << endl;
        q1.pop();
    }

    void peek()
    {
        if (q1.empty())
            cout << "Stack is empty\n";
        else
            cout << "Top element: " << q1.front() << endl;
    }

    void display()
    {
        if (q1.empty())
        {
            cout << "Stack is empty\n";
            return;
        }

        queue<int> temp = q1;

        cout << "Stack (top to bottom): ";

        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }

        cout << endl;
    }
};

int main()
{
    Stack s;
    int choice, x;

    do
    {
        cout << "\n1.Push  2.Pop  3.Peek  4.Display  0.Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter element: ";
            cin >> x;
            s.push(x);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            s.display();
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

