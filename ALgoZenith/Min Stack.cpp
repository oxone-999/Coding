#include<bits/stdc++.h>
using namespace std;

using lli = long long;

class MinStack {
public:
    lli ele;
    stack<lli> st;

    MinStack() {
        while(!st.empty()){
            st.pop();
        }
        ele = LLONG_MAX;
    }

    void push(lli x) {
        if(st.empty()){
            st.push(x);
            ele = x;
        } 
        else{
            if(x < ele){
                st.push(2*x-ele);
                ele = x;
            }else st.push(x);
        }
    }

    void pop() {
        if(!st.empty()){
            lli p = st.top();
            if(p < ele){
                ele = 2*ele-p;
            }
            st.pop();
        }
    }

    lli top() {
        if(st.empty()) return -1;
        else{
            if(st.top() < ele) return ele;
            else return st.top();
        }
    }

    lli getMin() {
        if(st.empty()) return -1;
        else return ele;
    }
};

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    lli q; cin >> q;

    MinStack s;

    while(q--) {
        string op;
        cin >> op;

        if(op == "push") {
            lli x;
            cin >> x;
            s.push(x);
        }
        else if(op == "pop") {
            s.pop();
        }
        else if(op == "top") {
            cout << s.top() << "\n";
        }
        else if(op == "getMin") {
            cout << s.getMin() << "\n";
        }
    }

    return 0;
}