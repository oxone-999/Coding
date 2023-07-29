//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const int MOD = 1e9+7;

struct Queue {
    stack<int> s1, s2;
 
    void Push(int x){
        s1.push(x);
    }
 
    int Pop()
    {
        if (!s2.empty()) {
            int x = s2.top();
            s2.pop();
            return x;
        }
 
        if(s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
 
        int x = s2.top();
        s2.pop();
        return x;
    }

    int Front(){
        if(!s2.empty()) return s2.top();
        else {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
};

void solve()
{
    int n;
    cin>>n;

    Queue q;

    while(n--){
        string s;
        cin>>s;

        if(s == "front"){
            cout<<q.Front()<<endl;
        }else if(s == "pop"){
            cout<<q.Pop()<<endl;
        }else if(s == "push"){
            int x;
            cin>>x;
            q.Push(x);
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}