//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;
lli n,x;

void func(vector<lli> &vec,lli j,vector<lli> &s,lli &sum,lli par){
    s.push_back(sum);

    for(lli i=j+1;i<(n+par)/2;i++){
        sum += vec[i];
        func(vec,i,s,sum,par);
        sum -= vec[i];
    }
}

void solve()
{
    cin>>n>>x;

    vector<lli> vec(n,0);
    for(auto &it:vec){
        cin>>it;
    }

    if(n == 1 ){
        cout<<vec[0]%x;
        return;
    }

    vector<lli> v1;
    vector<lli> v2;

    for(lli i=0;i<n/2;i++){
        v1.push_back(vec[i]);
    }

    for(lli i=n/2;i<n;i++){
        v2.push_back(vec[i]);
    }

    vector<lli> s1;
    vector<lli> s2;

    lli i = -1;
    lli sum = 0;
    func(v1,i,s1,sum,0);
    sum = 0;
    i = -1;
    func(v2,i,s2,sum,1);

    sort(all(s1));
    sort(all(s2));

    for(auto &it:s1){
        it %= x;
    }

    for(auto &it:s2){
        it %= x;
    }

    lli ans = 0;
    for(lli i=0;i<(int)s1.size();i++){
        lli target = (x - s1[i] - 1 + x)%x;
        lli ind = upper_bound(all(s2),target) - s2.begin();
        if(ind == 0){
            ind = (int)s2.size();
        }
        ans = max(ans,(s1[i]+s2[ind-1])%x);
    }

    cout<<ans<<endl;
}

signed main(){
    IOS
    solve();
    return 0;
}