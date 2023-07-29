//Standard Header Files
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"
#define MOD 1e9
#define all(a) (a).begin(), (a).end()

int 

void solve()
{
    int n;
    cin>>n;

    vector<int> vec(n,0);
    vector<int> pre(n,0);

    pre[0] = vec[0];
    for(auto &it:vec){
        cin>>it;
        pre[i] = pre[i-1] + it;
    }	

    int ans = 0;
    while(vec.size() != 1){
        int it = max_element(vec.begin(),vec.end()) - vec.begin();
        int mx = *max_element(vec.begin(),vec.end());
        int i;
        int j;
        for(i=it-1;i>=0;i--){
            if(vec[i] < mx){
                break;
            }
        }
        for(j=it+1;j<n;j++){
            if(vec[i] < mx){
                break;
            }
        }
        int sum = 0;
        sum += for(int k=i;k<=j;k++){
            sum += vec[k];
        }
    }
}

signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
int t=1;cin>>t;while(t--) solve();
return 0;
}