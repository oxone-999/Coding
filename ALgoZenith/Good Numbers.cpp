//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

const lli N = 1e6+1;

void solve()
{
    lli n,k,q;
    cin>>n>>k>>q;
    
    map<lli,lli> mp;
    map<lli,lli> mp2;
    vector<int> arr(N,0);

    for(lli i=0;i<n;i++){
        lli x,y;
        cin>>x>>y;
        mp[x] += 1;
        mp2[y] += 1;
    }

    lli mx = 0;
    for(lli i=0;i<N;i++){
        mx += mp[i];
        if(mx >= k) arr[i] = 1;
        mx -= mp2[i];
    }

    for(lli i=1;i<N;i++) arr[i] += arr[i-1];

    for(lli i=0;i<q;i++){
        lli l,r;
        cin>>l>>r;
        cout<<arr[r]-arr[l-1]<<endl;
    }
}

signed main(){
    IOS
    solve();
    return 0;
}