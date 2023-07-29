#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define deb(x) cout<<#x<<'='<<x<<endl
#define deb2(x,y) cout<<#x<<'='<<x<<','<<#y<<'='<<y<<endl
#define debvec(vec) fori(i,0,vec.size()) cout<<vec[i]<<" "
#define debarr(arr,n) fori(i,0,n) cout<<arr[i]<<" "
#define MOD 1e9

void solve()
{
    int n,k;
    cin>>n>>k;

    if(k%2 != 0){
        int j = 1;
        cout<<"YES"<<endl;
        for(int i=0;i<n/2;i++){
            cout<<j<<" "<<j+1<<endl;
            j += 2;
        }
    }
    else{
        int i = 1;
        bool flag = 1;
        vector<pair<int,int>> vec;
        for(int i=2,j=1;i<=n,j<=n;i+=2,j+=2){
            if(i%4 == 0){
                vec.push_back({j,i});
            }else if((i+k)%4 == 0){
                vec.push_back({i,j});
            }else{
                cout<<"NO"<<endl;
                flag = 0;
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
            for(auto it:vec){
                cout<<it.first<<" "<<it.second<<endl;
            }
        }
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
int t=1;cin>>t;while(t--) solve();
return 0;
}