#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    map<int,int> mp;
    int arr[] = {1,2,5,4,10000000};
    for(auto &v:arr)
    {
        mp[v];
    }
    vector<int> vec;
    int cnt = 0;

    for(auto &it:mp)
    {
        vec.push_back(it.first);
        it.second = cnt++;
    }

    for(int i=0;i<vec.size();i++)
        cout<<i<<" "<<vec[i]<<endl;

    cout<<endl;

    for(auto it:mp)
        cout<<it.first<<" "<<it.second<<endl;
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}