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
    vector<int> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }   	
    int mn = INT_MAX;
    int mn2 = INT_MAX;

    for(auto it:vec){
        if(mn > it){
            mn2 = mn;
            mn = it;   
        }else if(it < mn2 && it > mn){
            mn2 = it;
        }
    }
    if(mn2 == INT_MAX) cout<<-1<<endl;
    else cout<<mn2<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}