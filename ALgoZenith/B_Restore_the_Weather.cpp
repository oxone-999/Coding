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
    int n,k;
    cin>>n>>k;

    vector<int> vec1(n,0);
    vector<int> vec2(n,0);
    vector<pair<int,int>> v;

    for(int i=0;i<n;i++){
        cin>>vec1[i];
        v.push_back({vec1[i],i});
    }


    for(auto &it:vec2){
        cin>>it;
    }

    sort(all(v));
    sort(all(vec2));

    vector<pair<int,int>> v2;

    for(int i=0;i<n;i++){
        v2.push_back({v[i].second,vec2[i]});
    }

    sort(all(v2));

    for(int i=0;i<n;i++){
        cout<<v2[i].second<<" ";
    }
    cout<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}