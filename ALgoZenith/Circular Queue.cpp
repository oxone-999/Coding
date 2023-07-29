#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue
{
public:
    
    int front;
    int rear;
    int cap;
    vector<int> arr;

    MyCircularQueue(int k)
    {
        front = -1;
        rear = -1;
        cap = k;
        arr.assign(cap,0);
    }

    bool enQueue(int value)
    {
        if(front == -1 && rear == -1){
            front = rear = 0;
        }
        else if((rear+1)%cap == front) return 0;
        else {
            rear++;
            rear %= cap;
        }
        arr[rear] = value;
        return 1;
    }

    bool deQueue()
    {
        if(front == -1 && rear == -1){
            return 0;
        }
        else if(front == rear){
            front = rear = -1;
        }
        else {
            front++;
            front %= cap;
        }
        return 1;
    }

    int Front()
    {
        if(rear == -1 && front == -1) return -1;
        return arr[front];
    }

    int Rear()
    {
        if(rear == -1 && front == -1) return -1;
        return arr[rear];
    }

    bool isEmpty()
    {
        if(rear == -1 && front == -1) return 1;
        else return 0;
    }

    bool isFull()
    {
        if((rear+1)%cap == front) return 1;
        else return 0;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    int k;
    cin >> k;

    MyCircularQueue myCircularQueue(k);

    while (q--)
    {
        string s;
        cin >> s;

        if (s == "enQueue")
        {
            int val;
            cin >> val;

            if (myCircularQueue.enQueue(val))
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "deQueue")
        {
            if (myCircularQueue.deQueue())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "Front")
        {
            cout << myCircularQueue.Front() << "\n";
        }
        else if (s == "Rear")
        {
            cout << myCircularQueue.Rear() << "\n";
        }
        else if (s == "isEmpty")
        {
            if (myCircularQueue.isEmpty())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "isFull")
        {
            if (myCircularQueue.isFull())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else
        {
            assert(1 == 0); //This never happen
        }
    }

    return 0;
}