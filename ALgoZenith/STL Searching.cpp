//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const int MOD = 1e9+7;

void solve()
{
    int n,q;
    cin>>n>>q;

    vector<int> vec(n,0);

    for(auto &it:vec){
        cin>>it;
    }

    sort(vec.begin(),vec.end());

    for(int i=0;i<q;i++){
        int ch,x;
        cin>>ch>>x;

        if(ch == 1){
            int ind = lower_bound(vec.begin(),vec.end(),x) - vec.begin();
            if(ind+vec.begin() == vec.end()) cout<<(-1)<<" ";
            else cout<<vec[ind]<<" ";
        }else if(ch == 2){
            int ind = upper_bound(vec.begin(),vec.end(),x) - vec.begin();
            if(ind+vec.begin() == vec.end()) cout<<(-1)<<" ";
            else cout<<vec[ind]<<" ";
        }else if(ch == 3){
            int ind = upper_bound(vec.begin(),vec.end(),x) - vec.begin();
            if(ind+vec.begin() == vec.end()) cout<<n<<" ";
            else cout<<ind<<" ";
        }else{
            int ind = lower_bound(vec.begin(),vec.end(),x) - vec.begin();
            if(ind+vec.begin() == vec.end()) cout<<n<<" ";
            else cout<<ind<<" ";
        }
    }cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}