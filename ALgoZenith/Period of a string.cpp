//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

//KMP algorithm
vector<lli> kmp(string s,lli n){
    lli i = 0;
    lli j = -1;
    vector<lli> km(n+1,0);
    km[0] = -1;

    while(i < n){
        while(j != -1 && s[i]!=s[j]) j = km[j];
        i++;j++;
        km[i] = j;
    }
    return km;
}

void solve()
{
    lli n;
    cin>>n;
    string s;
    cin>>s;

    vector<lli> km = kmp(s,n);

    for(lli i=1;i<=n;i++){
        lli l = km[i];
        // p = N - KMP(last)
        lli p = i - l;
        if(p != 0 && (i % p) == 0 && (i/p) > 1){
            cout<<i<<" "<<i/p<<endl;
        }
    }cout<<endl;
}

signed main(){
    IOS
    lli x = 1;
    lli t=1;cin>>t;while(t--){
        cout<<"Test case #"<<x<<endl;
        solve();
        x++;
    } 
    return 0;
}