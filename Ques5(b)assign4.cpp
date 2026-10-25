
#include <iostream>
#include <queue>
using namespace std;

class Stack
{
    queue<int> q;

public:
    void push(int x)
    {
        int n = q.size();

        q.push(x);

        for (int i = 0; i < n; i++)
        {
            q.push(q.front());
            q.pop();
        }

        cout << "Element pushed\n";
    }

    void pop()
    {
        if (q.empty())
        {
            cout << "Stack Underflow\n";
            return;
        }

        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    void peek()
    {
        if (q.empty())
            cout << "Stack is empty\n";
        else
            cout << "Top element: " << q.front() << endl;
    }

    void display()
    {
        if (q.empty())
        {
            cout << "Stack is empty\n";
            return;
        }

        queue<int> temp = q;

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

