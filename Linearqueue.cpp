#include <bits/stdc++.h>
using namespace std;
#define MAX_SIZE 105 // maximum size of the queue



class Queue
{
private:
    int front, rear;
    int arr[MAX_SIZE];

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty()
    {
        return (front == -1 && rear == -1);
    }

    bool isFull()
    {
        return (rear == MAX_SIZE - 1);
    }

    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "Error: Queue is full\n";
            return;
        }
        else if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = x;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Error: Queue is empty\n";
            return;
        }
        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }

    int getFront()
    {
        if (isEmpty())
        {
            cout << "Error: Queue is empty\n";
            return -1;
        }
        return arr[front];
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.display();
    q.dequeue();
    q.display();
    cout << "Front element: " << q.getFront() << endl;
    return 0;
}
