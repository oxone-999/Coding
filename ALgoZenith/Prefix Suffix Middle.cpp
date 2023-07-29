//Standard Header Files
#include<bits/stdc++.h>
using namespace std;
using lli = long long;

#define IOS ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"
#define all(a) (a).begin(), (a).end()

const lli mod = 1e9+7;

//KMP algorithm
vector<int> kmp(string s,int n){
    int i = 0;
    int j = -1;
    vector<int> kmp(n+1,0);
    kmp[0] = -1;

    while(i < n){
        while(j != -1 && s[i]!=s[j]) j = kmp[j];
        i++;j++;
        kmp[i] = j;
    }
    return kmp;
}

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;

    vector<int> k = kmp(s,n);

    int l = k[n];

    if(l == 0){
        cout<<(-1)<<endl;
        return;
    }
    for(int i=2;i<n;i++){
        if(k[i] == l){
            string ans(s.begin(),s.begin()+l);
            cout<<ans<<endl;
            return;
        }
    }

    if(k[k[n]] == 0){
        cout<<(-1)<<endl;
        return;
    }else{
        string ans(s.begin(),s.begin()+k[k[n]]);
        cout<<ans<<endl;
        return;
    }

    cout<<(-1)<<endl;
}

signed main(){
    IOS
    lli t=1;cin>>t;while(t--) solve();
    return 0;
}