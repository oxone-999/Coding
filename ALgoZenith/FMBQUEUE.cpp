#include <bits/stdc++.h>
using namespace std;

class FrontMiddleBackQueue
{
public:
    deque<int> dq1,dq2;

    FrontMiddleBackQueue()
    {
        dq1.clear();
        dq2.clear();
    }
    
    void pushFront(int val)
    {
        if(dq1.size() == dq2.size()){
            dq1.push_front(val);
        }else{
            dq1.push_front(val);
            int x = dq1.back();
            dq1.pop_back();
            dq2.push_front(x);
        }
    }

    void pushMiddle(int val)
    {
        if(dq1.size() == dq2.size()){
            dq1.push_back(val);
        }else{
            int x = dq1.back();
            dq1.pop_back();
            dq1.push_back(val);
            dq2.push_front(x);
        }
    }

    void pushBack(int val)
    {
        if(dq1.size() == dq2.size()){
            dq2.push_back(val);
            int y = dq2.front();
            dq2.pop_front();
            dq1.push_back(y);
        }else{
            dq2.push_back(val);
        }
    }

    int popFront()
    {
        if(dq1.size() == dq2.size()){
            if(dq1.empty()){
                return -1;
            }
            int x = dq1.front();
            dq1.pop_front();
            int y = dq2.front();
            dq2.pop_front();
            dq1.push_back(y);
            return x;
        }else{
            int x = dq1.front();
            dq1.pop_front();
            return x;
        }
    }

    int popMiddle()
    {
        if(dq1.empty()) return -1;
        int x = dq1.back();
        dq1.pop_back();
        if(dq1.size() < dq2.size()){
            int y = dq2.front();
            dq2.pop_front();
            dq1.push_back(y);
        }
        return x;
    }

    int popBack()
    {
        if(dq1.empty()) return -1;
        if(dq1.size() == dq2.size()){
            int x = dq2.back();
            dq2.pop_back();
            return x;
        }else if(!dq2.empty()){
            int y = dq2.back();
            dq2.pop_back();
            int x = dq1.back();
            dq1.pop_back();
            dq2.push_front(x);
            return y;
        }else{
            int x = dq1.back();
            dq1.pop_back();
            return x;
        } 
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;
    FrontMiddleBackQueue *obj = new FrontMiddleBackQueue();
    for (int i = 0; i < q; i++)
    {
        string op;
        cin >> op;
        if (op == "pushFront")
        {
            int val;
            cin >> val;
            obj->pushFront(val);
        }
        else if (op == "pushMiddle")
        {
            int val;
            cin >> val;
            obj->pushMiddle(val);
        }
        else if (op == "pushBack")
        {
            int val;
            cin >> val;
            obj->pushBack(val);
        }
        else if (op == "popFront")
        {
            cout << obj->popFront() << '\n';
        }
        else if (op == "popMiddle")
        {
            cout << obj->popMiddle() << '\n';
        }
        else if (op == "popBack")
        {
            cout << obj->popBack() << '\n';
        }

        // for(auto it:obj->dq1) cerr<<it<<" ";
        // cerr<<" ";
        // for(auto it:obj->dq2) cerr<<it<<" ";
        // cerr<<endl;

    }
    return 0;
}