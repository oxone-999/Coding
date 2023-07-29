#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

void solve()
{
    int n,m;
    cin>>n>>m;

    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        mp[x]++;
    }    

    vector<pair<int,int>> vec;

    for(auto it:mp){
        vec.push_back({it.second,it.first});
    }
    int ans = mp.size();

    sort(vec.begin(),vec.end());

    for(int i=0;i<vec.size();i++){
        if(m < vec[i].first){
            break;
        }
        else {
            m -= vec[i].first;
            ans--;
        }
    }

    cout<<ans<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}