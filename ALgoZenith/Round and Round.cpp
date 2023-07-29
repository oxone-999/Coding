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

    string s;
    cin>>s;

    int x = 0;
    int y = 0;

    pair<int,int> dir[4] = {{-1,0},{0,1},{1,0},{0,-1}};
    int d = 0;

    for(int i=0;i<n;i++){
        if(s[i] == 'W'){
            x += dir[d].first;
            y += dir[d].second;
        }else if(s[i] == 'L'){
            d--;
            d = ((d%4)+4)%4;
        }else{
            d++;
            d %= 4;
        }
        cout<<x<<" "<<y<<endl;
    }
    if(x == 0 && y == 0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}