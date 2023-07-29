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

    vector<pair<string,int>> vec;
    for(int i=0;i<n;i++){
        string name;
        int roll;
        cin>>name>>roll;
        vec.push_back({name,roll});
    }

    sort(vec.begin(),vec.end(),[](pair<string,int> &a,pair<string,int> &b){
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    for(auto it:vec){
        cout<<it.first<<" "<<it.second<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}