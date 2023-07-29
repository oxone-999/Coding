//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const int MOD = 1e9+7;

void solve()
{
    int n,m;
    cin>>n>>m;

    string st = "";
    st = string(3*m+1,'*');
    cout<<st<<endl;

    string dd = "..*";

    for(int i=0;i<n;i++){
        cout<<'*';
        for(int j=0;j<m;j++){
            cout<<dd;
        }
        cout<<endl<<'*';
        for(int j=0;j<m;j++){
            cout<<dd;
        }
        cout<<endl<<st<<endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}