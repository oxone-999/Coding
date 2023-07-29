#include <bits/stdc++.h>
using namespace std;

class MyCircularDeque
{
public:

    int front;
    int rear;
    int cap;
    vector<int> arr;
   
    MyCircularDeque(int k)
    {
        front = -1;
        rear = -1;
        cap = k;
        arr.assign(cap,0);
    }

    bool insertFront(int value)
    {
        if(front == -1 && rear == -1){
            front = rear = 0;
        }
        else if((front-1+cap)%cap == rear) return 0;
        else {
            front--;
            front = (front+cap)%cap;
        }
        arr[front] = value;
        return 1;
    }

    bool insertLast(int value)
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

    bool deleteFront()
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

    bool deleteLast()
    {
        if(front == -1 && rear == -1){
            return 0;
        }
        else if(front == rear){
            front = rear = -1;
        }
        else {
            rear--;
            rear = (rear+cap)%cap;
        }
        return 1;
    }

    int getFront()
    {
        if(rear == -1 && front == -1) return -1;
        return arr[front];
    }

    int getRear()
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

    MyCircularDeque myCircularDeque(k);

    while (q--)
    {
        string s;
        cin >> s;

        if (s == "insertFront")
        {
            int val;
            cin >> val;
            if (myCircularDeque.insertFront(val))
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "insertLast")
        {
            int val;
            cin >> val;
            if (myCircularDeque.insertLast(val))
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "deleteFront")
        {
            if (myCircularDeque.deleteFront())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "deleteLast")
        {
            if (myCircularDeque.deleteLast())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "getFront")
        {
            cout << myCircularDeque.getFront() << "\n";
        }
        else if (s == "getRear")
        {
            cout << myCircularDeque.getRear() << "\n";
        }
        else if (s == "isEmpty")
        {
            if (myCircularDeque.isEmpty())
                cout << "True\n";
            else
                cout << "False\n";
        }
        else if (s == "isFull")
        {
            if (myCircularDeque.isFull())
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