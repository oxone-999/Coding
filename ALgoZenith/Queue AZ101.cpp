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

    queue<int> q;

    while(n--){
        string s;
        cin>>s;

        if(s == "add"){
            int x;
            cin>>x;
            q.push(x);
        }else if(s == "remove"){
            if(!q.empty()) q.pop();
        }else{
            if(!q.empty()) cout<<q.front()<<endl;
            else cout<<0<<endl;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}