#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool isOperator(char ch)
{
    if(ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '^')
        return true;
    return false;
}

int prec(char ch)
{
    if(ch == '^') return 3;
    if(ch == '/' || ch == '*') return 2;
    if(ch == '+' || ch == '-') return 1;
    return -1;
}
// Function to convert an infix expression to a postfix expression.
string infixToPostfix(string A) {
    stack<char> s;
    int n = A.size();
    string str;
    
    for(int i=0;i<n;i++)
    {
        if(A[i] == '(') s.push(A[i]);
        else if(A[i] == ')'){
            while(!s.empty() && s.top() != '(')
            {
                str += s.top();
                s.pop();
            }
            if(!s.empty()) s.pop();
        }
        else if(isOperator(A[i]))
        {
            while(!s.empty() && prec(s.top()) >= prec(A[i]))
            {
                str += s.top();
                s.pop();
            }
            s.push(A[i]);
        }
        else str += A[i];
    }
    
    while(!s.empty())
    {
        str += s.top();
        s.pop();
    }
    
    return str;
}


void solve()
{
    string A;
    cin>>A;
    cout<<infixToPostfix(A)<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}