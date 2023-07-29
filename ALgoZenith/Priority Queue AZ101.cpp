//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

void solve()
{
    int q;
    cin>>q;

    priority_queue<int> pq;
    while(q--){
        string s;
        cin>>s;

        if(s == "add"){
            int x;
            cin>>x;
            pq.push(x);
        }else{
            if(s == "print"){
                if(pq.empty()) cout<<0<<endl;
                else cout<<pq.top()<<endl;
            }else{
                if(!pq.empty()){
                    pq.pop();
                } 
            }
        }
    }
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}