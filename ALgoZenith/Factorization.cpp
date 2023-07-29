//Standard Header Files
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

#define int long long
#define endl "\n"
#define MOD 1e9+7
#define all(a) (a).begin(), (a).end()

void solve()
{
    int n;
    cin>>n;
    set<int> s;

    for(int i=1;i*i<=n;i++){
        if(n%i == 0){
            s.insert(i);
            s.insert(n/i);
        }
    }
    for(auto it:s){
        cout<<it<<" ";
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
solve();
return 0;
}