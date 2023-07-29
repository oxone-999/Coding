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
    int n;
    cin>>n;
    
    vector<int> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }

    priority_queue<int,vector<int>,greater<int>> pq;

    int x = 0;

    for(int i=0;i<n;i++){
        if(x < vec[i]) pq.push(vec[i]);
        while(!pq.empty() && pq.top() <= x){
            pq.pop();
        }
        if(pq.size() > x) x++;
        cout<<x<<" ";
    }cout<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}