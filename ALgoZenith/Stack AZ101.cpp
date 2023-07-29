//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const int MOD = 1e9+7;

void solve()
{
    int n;
    cin>>n;

    stack<int> st;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;

        if(s == "add"){
            int x;
            cin>>x;
            st.push(x);
        }else if(s == "print"){
            if(st.empty()) cout<<0<<endl;
            else cout<<st.top()<<endl;
        }else if(s == "remove"){
            if(!st.empty()) st.pop();
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}