//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const int MOD = 1e9+7;

void solve()
{
    int n,m,c;
    cin>>n>>m>>c;

    string st = "";
    st = string((c+1)*m+1,'*');
    cout<<st<<endl;

    bool phase = true;
    for(int i=0;i<n;i++){
        for(int k=0;k<c;k++){
            cout<<'*';
            if(i % 2 == 0) phase = true;
            else phase = false;
            for(int j=0;j<m;j++){
                string z = string(c,'.');
                if(phase =){
                    z[k] = '\\';
                    phase = false;
                }else{
                    z[c-k-1] = '/';
                    phase = true;
                } 
                cout<<z<<"*";
            }
            cout<<endl;
        }
        phase = !phase;
        cout<<st<<endl;
    }
    cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}