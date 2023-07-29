//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const int MOD = 1e9+7;

void solve()
{
    string s;
    cin>>s;

    stack<char> st;

    for(auto it:s){
        if(it == '(') st.push(it);
        else{
            if(!st.empty() && st.top() == '('){
                st.pop();
            }else st.push(it);
        }
    } 
    cout<<st.size()<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}