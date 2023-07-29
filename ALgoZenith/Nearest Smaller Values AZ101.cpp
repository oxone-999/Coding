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

    stack<pair<int,int>> s;

    for(int i=0;i<n;i++){
        if(s.empty()) cout<<0<<" ";
        else if(s.top().first >= vec[i]){
            while(!s.empty() && s.top().first >= vec[i]){
                s.pop();
            }
            if(!s.empty()){
                cout<<s.top().second<<" ";
            }else cout<<0<<" ";
        }else cout<<s.top().second<<" ";
        s.push({vec[i],i+1});
    }cout<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}