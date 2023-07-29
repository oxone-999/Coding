#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string str,pat;
    cin>>str>>pat;
    int n = str.size();
    int l = pat.size();

    const int p = 31;
    const int m = 1e9 + 9;

    vector<long long> p_pow(max(n,l)+1,0);
    p_pow[0] = 1;
    for(int i=0;i<max(n,l);i++)
        p_pow[i+1] = (p_pow[i]*p)%m;

    vector<long long> h(n+1,0);
    for(int i=0;i<n;i++)
        h[i+1] = (h[i] + ((str[i]-'A'+1)*p_pow[i])%m)%m;

    long long h2 = 0;
    for(int i=0;i<l;i++)
        h2 = (h2 + ((pat[i]-'A'+1)*p_pow[i])%m)%m;

    vector<int> ans;
    for(int i=0;i<=n-l;i++){
        long long curr = (h[i+l] + m - h[i])%m;
        if(curr == (h2 * p_pow[i])%m){
            ans.push_back(i);
        }
    }
    if(ans.size() != 0) cout<<ans.size()<<endl;
    for(auto it:ans){
        cout<<it+1<<" ";
    }
    if(ans.size() == 0) cout<<"Not Found";
    cout<<endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;cin>>t;while(t--) solve();
    return 0;
}