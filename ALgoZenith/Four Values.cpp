//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;
map<int,pair<int,int>> mp;

void solve()
{
    int n,sum;
    cin>>n>>sum;

    vector<int> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(mp.count(sum-(vec[i]+vec[j]))){
                pair<int,int> x = mp[sum-(vec[i]+vec[j])];
                if(x.first == i || x.first == j || x.second == i || x.second == j) continue;
                cout<<"YES"<<endl;
                return;
            }
            mp[vec[i]+vec[j]] = {i,j};
        }
    }
    cout<<"NO"<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}