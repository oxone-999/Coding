#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

class MinStack{
    public:
    int minEle;
    stack<int> s;

    MinStack() {
        s = stack<int>();
        minEle = 0;
    }
    void pop();
    int getMin();
    void push(int x);
    int top();
};


void MinStack::push(int x) {
    if(s.size() == 0)
    {
        s.push(x);
        minEle = x;
    }
    else 
    {
        if(x >= minEle) s.push(x);
        else 
        {
            s.push(2*x-minEle);
            minEle = x;
        }
    }
}

void MinStack::pop() {
    if(s.size() == 0) return;
    else 
    {
        if(s.top() >= minEle) s.pop();
        else if(s.top() < minEle)
        {
            minEle = 2*minEle-s.top();
            s.pop();
        }
    }
}

int MinStack::top() {
    if(s.size() == 0) return -1;
    else 
    {
        if(s.top()>=minEle) return s.top();
        else return minEle;
    }
}

int MinStack::getMin() {
    if(s.size() == 0) return -1;
    else return minEle;
}

void solve()
{
    MinStack s;

    s.push(1);
    s.push(4);
    s.push(3);
    cout<<s.top()<<endl;
    cout<<s.getMin()<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    solve();
    return 0;
}