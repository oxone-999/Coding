//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const int MOD = 1e9+7;

void solve()
{
    int ch;
    cin>>ch;
    int n;
    cin>>n;

    if(ch == 1){
        for(int i=0;i*i<=n;i++){
            if(i*i == n){
                cout<<"YES"<<endl;
                return;
            } 
        }cout<<"NO"<<endl;
    }else{
        for(int i=0;i*i*i<=n;i++){
            if(i*i*i == n){
                cout<<"YES"<<endl;
                return;
            } 
        }cout<<"NO"<<endl;
    }

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}