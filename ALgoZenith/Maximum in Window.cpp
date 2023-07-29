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
    lli n,k;
    cin>>n>>k;
    
    vector<lli> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }

    deque<lli> dq;

    lli i=0;
    lli j=0;

    while(j<n){
        while(!dq.empty() && dq.back() < vec[j]){
            dq.pop_back();
        }
        dq.push_back(vec[j]);
        if(j-i+1 == k){
            cout<<dq.front()<<" ";
            if(vec[i] == dq.front()) dq.pop_front();
            i++;
        }
        j++;
    }cout<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}